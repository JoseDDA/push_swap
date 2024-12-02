/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_preparation_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:45:34 by jdorazio          #+#    #+#             */
/*   Updated: 2024/12/02 09:46:23 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"


/*
	Assigns each node in the stack an index and a median flag.
	Nodes with indices ≤ median are marked with median = 1; others with median = 0.
*/
void	assign_stack_index_and_median(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = ft_stack_size(stack)/2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->median = 1;
		else
			stack->median = 0;
		stack = stack->next;
		i++;
	}
}

/* 
	For each node in stack A, find the target node in stack B.
	The target node in B is the largest node smaller than the current node in A.
	If no such node exists, the highest node in B is selected as the target.
*/
void	assign_targets_in_B(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target_node;
	t_stack	*currA;
	t_stack	*currB;

	if(!stack_a || !stack_b)
		return;
	currA = stack_a;
	while (currA)
	{
		target_node = NULL;
		currB = stack_b;
		while (currB)
		{
			if (currB->value < currA->value)
				if (!target_node || currB->value > target_node->value)
					target_node = currB;
			currB = currB->next;
		}
		if (!target_node)
			target_node = highest_node_value(stack_b);
		currA->target_node = target_node;
		currA = currA->next;
	}
}

/*
Calculates the cost of moving each node in stack A to its target position in stack B.
The cost considers rotations and shared movements between the stacks.
*/
void	calculate_push_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	a_size;
	int	b_size;
	int	cost_a;
	int	cost_b;

	a_size = ft_stack_size(stack_a);
	b_size = ft_stack_size(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		cost_a = stack_a->index;
		cost_b = 0;
		if (stack_a->median == 0)
			cost_a = a_size - stack_a->index;
		if (stack_a->target_node->median == 1)
			cost_b = stack_a->target_node->index;
		else
			cost_b = b_size - stack_a->target_node->index;
		if (stack_a->median == stack_a->target_node->median)
			stack_a->push_cost = cost_a + cost_b - shared_cost(cost_a, cost_b);
		else
			stack_a->push_cost = cost_a + cost_b;
		stack_a = stack_a->next;
	}
}

int	shared_cost(int cost_a, int cost_b)
{
	if (cost_a < cost_b)
		return (cost_a);
	return (cost_b);
}

/* 
Finds the node with the lowest push cost in the stack and marks it as the cheapest.
*/
void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_node = NULL;
	while (stack)
	{
		if (!cheapest_node || stack->push_cost < cheapest_node->push_cost)
			cheapest_node = stack;
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = 1;
}
