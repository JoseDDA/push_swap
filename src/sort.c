/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:33:52 by jdorazio          #+#    #+#             */
/*   Updated: 2024/11/28 14:00:14 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


// Check if Stack A is already Sorted. If yes, just return
int	sorted(t_stack *sA)
{
	t_stack	*curr;

	curr = sA;
	while (curr -> next != NULL)
	{
		if (curr -> value > curr -> next -> value)
			return (0);
		curr = curr -> next;
	}
	return (1);
}

void	sort_three(t_stack **sA)
{
	t_stack	*max_node;

	max_node = ft_max(*sA);
	if (max_node == *sA)
		rot_a(sA);
	else if ((*sA) -> next == max_node)
		rev_rot_a(sA);
	if ((*sA) -> value > (*sA) -> next -> value)
		swap_a(sA);
}


/*
	IF pushed Number is Neither Maximum or Minimum from the Stack B -> Push somewhere
		Checked whether the TARGET_NUMBERED in Stack B is MAX or MIN
	Push only until STACK_SIZE = 3

*/
void	sort_stacks(t_stack **sA, t_stack **sB)
{
	int	s_size;

	s_size = ft_stack_size(*sA);
	if (s_size-- > 3 && !sorted(*sA))
		push_b(sA, sB);
	if (s_size-- > 3 && !sorted(*sA))
		push_b(sA, sB);
	// printf("Actual size = %d\n", s_size);
	while (s_size > 3 && !sorted(*sA))
	{
		// printf("Sort_stacks enters Loop\n");
		move_node_A_to_B(sA, sB);
		s_size--;
	}
	sort_three(sA);

}

/*
	Find_Index:
		- Asigna un valor al [index] de cada Nodo Restante en el Stack A
		- Asigna un valor booleano al [above_median]
		- Example: 10 20 30 40 50
			10 , 20 , 30 are above the median, therefore have 1.
			40 50 are below the median, therefore 0
*/
void	find_index_median(t_stack *sA)
{
	int	i;
	int	median;

	i = 0;
	if (!sA)
		return;
	median = ft_stack_size(sA) / 2;
	while (sA)
	{
		sA -> index = i++;
		if (median > i)
			sA -> above_median = 1;
		else
			sA -> above_median = 0;
		sA = sA -> next;
	}
}
/*
	Find_Target:
		- Finds the TARGET_NODE for each Node in A
		- We sorting in descending order, therefore the target node is the largest node in
			Stack B that is smaller than the current node in Stack A
*/
void	find_target_A(t_stack *sA, t_stack *sB)
{
	t_stack	*curr_B;
	t_stack	*target;

	while (sA)
	{
		curr_B = sB;
		target = NULL;
		while (curr_B)
		{
			if (sA->value < curr_B->value)
				if (!target || curr_B->value < target->value)
					target = curr_B;
			curr_B = curr_B -> next;
		}
		if (!target)
			sA->target_node = ft_max(sB);
		else
			sA->target_node = target;
		sA = sA->next;
	}
}


/* To Find Cost, we need first to find the TARGET
	Example:
*/
void	find_cost(t_stack *sA, t_stack *sB)
{
	int	size_A;
	int	size_B;

	if (!sA || !sB)
		return;
	size_A = ft_stack_size(sA);
	size_B = ft_stack_size(sB);
	while (sA)
	{
		if (sA->above_median == 1) // Above median
			sA->push_cost = sA->index; // Rotate Forward
		else  // Below median
			sA->push_cost = size_A - sA->index; // Rotate Backward
		if (sA->target_node)
		{
			if (sA->target_node->above_median == 1) // Above median
				sA->push_cost += sA->target_node->index; // Rotate forward in Stack B
			else
				sA->push_cost += size_B -sA->target_node->index; // Rotate backward in Stack B
		}
		sA = sA->next;
	}
}

/*

*/
void	find_cheapest(t_stack *sA)
{
	t_stack	*cheapest_node;
	t_stack	*curr;

	if (!sA)
		return;
	cheapest_node = sA;
	curr = sA;
	while (curr)
	{
		curr -> cheapest = 0;
		curr = curr -> next;
	}
	while (sA)
	{
		if (cheapest_node->push_cost > sA->push_cost)
			cheapest_node = sA;
		sA = sA->next;
	}
	cheapest_node->cheapest = 1;
}


void	init_nodes_A(t_stack *sA, t_stack *sB)
{
	find_index_median(sA);
	find_index_median(sB);
	find_target_A(sA, sB);
	find_cost(sA, sB);
	find_cheapest(sA);
}



t_stack	*get_cheapest(t_stack *src)
{
	if (!src)
		return (NULL);
	while (src)
	{
		if (src->cheapest)
			return src;
		src = src->next;
	}
	return (NULL);
}


 void	rot_both(t_stack *sA, t_stack *sB, t_stack *cheapest_node)
 {
	if (!sA || !sB || !cheapest_node)
		return;
	while (cheapest_node->index != 0 && cheapest_node->target_node->index--!= 0) //if Both true rev_rot
	{
		rot_a(&sA);
		rot_b(&sB);
		write(1, "rr\n", 4);
		cheapest_node->index--;
		cheapest_node->target_node->index--;
	}
	while (cheapest_node->index != 0)
	{
		rot_a(&sA);
		cheapest_node->index--;
	}
	while (cheapest_node->target_node->index != 0)
	{
		rot_b(&sB);
		cheapest_node->target_node->index--;
	}
 }

void	rev_rot_both(t_stack *sA, t_stack *sB, t_stack *cheapest_node)
 {
	if (!sA || !sB || !cheapest_node)
		return;
	while (cheapest_node->index != 0 && cheapest_node->target_node->index--!= 0) //if Both true rev_rot
	{
		rot_a(&sA);
		rot_b(&sB);
		write(1, "rrr\n", 4);
		cheapest_node->index++;
		cheapest_node->target_node->index++;
	}
	while (cheapest_node->index != 0)
	{
		rot_a(&sA);
		cheapest_node->index++;
	}
	while (cheapest_node->target_node->index != 0)
	{
		rot_b(&sB);
		cheapest_node->target_node->index++;
	}
 }

void	prep_node(t_stack *src)
{
	if (!src)
		return;

}


void	move_node_A_to_B(t_stack **sA, t_stack **sB)
{
	t_stack	*cheapest_node;

	if (!sA || !sB)
		return;
	init_nodes_A(*sA,*sB);
	cheapest_node = get_cheapest(*sA); // this tell's which node is cheaper
	if (!cheapest_node)
		return;
	// printf("Cheapest Node %d\n", cheapest_node->value);
	// printf("Index: %d\n" , cheapest_node->index);
	// printf("Target_Index Stack B: %d\n", cheapest_node->target_node->index);
	// printf("Target_Node Number: %d\n", cheapest_node->target_node->value);

	if (cheapest_node->above_median == 1 && cheapest_node->target_node->above_median == 1)
		rot_both(*sA, *sB, cheapest_node);
	else if (cheapest_node->above_median == 0 && cheapest_node->target_node->above_median == 0)
		rev_rot_both(*sA, *sB, cheapest_node);
	if (cheapest_node->index == 1)
		swap_a(sA);
	if (cheapest_node->target_node->index == 1)
		swap_b(sB);
	push_b(sA, sB);
	init_nodes_A(*sA,*sB);
}
