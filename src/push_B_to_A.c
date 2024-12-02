/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_B_to_A.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:46:24 by jdorazio          #+#    #+#             */
/*   Updated: 2024/12/02 09:32:09 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

/*
Assigns a target node in Stack A for each node in Stack B. 
The target node in Stack A is the smallest node with a value greater than the current node 
in Stack B. If no such node exists, the target node will be the node with the smallest 
value in Stack A.
*/
void	assign_targets_in_A(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target_node;
	t_stack	*currA;
	t_stack	*currB;

	if(!stack_a || !stack_b)
		return;
	currB = stack_b;
	while (currB)
	{
		target_node = NULL;
		currA = stack_a;
		while (currA)
		{
			if (currB->value < currA->value)
				if (!target_node || currA->value < target_node->value)
					target_node = currA;
			currA = currA->next;
		}
		if (!target_node)
			target_node = lowest_node_value(stack_a);
		currB->target_node = target_node;
		currB = currB->next;
	}
}

/*
	Initializes Stack B by calculating median indices for both stacks 
	and assigning target nodes in Stack A for each node in Stack B.
*/

void	prepare_stack_b_for_sorting(t_stack *stack_a, t_stack *stack_b)
{
	assign_stack_index_and_median(stack_a);
	assign_stack_index_and_median(stack_b);
	assign_targets_in_A(stack_a, stack_b);
}

/*
    Moves the top node of Stack B to Stack A. 
    Ensures the target node in Stack A is properly positioned 
    before the push operation.
*/
void	push_B_to_A (t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	align_stacks_for_push(stack_a, (*stack_b)->target_node, 'a');
	push(stack_b, stack_a, 1);
}
