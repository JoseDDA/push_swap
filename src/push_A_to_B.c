/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_A_to_B.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:26:04 by jdorazio          #+#    #+#             */
/*   Updated: 2024/12/02 09:29:00 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

/*
	Finds the node marked as "cheapest" (where node->cheapest == 1) in the given stack.
	Returns the pointer to the cheapest node, or NULL if no such node exists.
*/

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return  (NULL);
}

/*
	Simultaneously rotates both stacks until the specified cheapest_node is at the top of one of the stacks.
	Updates the stack indices and median flags after rotations.
*/

void	rotate_both_stacks(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node)
	{
		rot(stack_a, 2);
		rot(stack_b, 2);
	}
	assign_stack_index_and_median(*stack_a);
	assign_stack_index_and_median(*stack_b);	
}

/*
	Simultaneously reverse rotates both stacks until the specified cheapest_node is at the top of one of the stacks.
	Updates the stack indices and median flags after rotations.
*/

void	reverse_rotate_both_stacks (t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node)
	{
		rev_rot(stack_a, 2);
		rev_rot(stack_b, 2);
	}
	assign_stack_index_and_median(*stack_a);
	assign_stack_index_and_median(*stack_b);
}

/*
	Rotates the specified stack individually until the given cheapest_node is at the top.
	The `name` parameter indicates whether this operation applies to stack A ('a') or stack B ('b').
*/

void	align_stacks_for_push (t_stack **stack, t_stack *cheapest_node, char name)
{
	if (!stack ||!*stack || !cheapest_node)
	    {
        return;
    }
	while (*stack != cheapest_node)
	{
		if (name == 'a')
		{
			if (cheapest_node->median == 1)
				rot(stack, 0); // Assuming rot() function is defined elsewhere
			else
				rev_rot(stack, 0); // Assuming rev_rot() function is defined elsewhere
		}
		else if (name == 'b')
		{
			if (cheapest_node->median == 0)
				rot(stack, 1); // Assuming rot() function is defined elsewhere
			else
				rev_rot(stack, 1); // Assuming rev_rot() function is defined elsewhere
		}
	}
}
/*
	Aligns both stacks so that the "cheapest" node from stack A can be pushed to stack B.
	Uses simultaneous rotations or reverse rotations, then aligns each stack individually
	to ensure the cheapest_node and its target_node are in the correct positions for the push operation.
*/

void	push_A_to_B(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	if(!stack_a || !stack_b)
		return;

	cheapest_node = get_cheapest(*stack_a);
	if (!cheapest_node || !cheapest_node->target_node)
		return;
	if (cheapest_node->median == 1 && cheapest_node->target_node->median == 1)
		rotate_both_stacks(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->median == 0 && cheapest_node->target_node->median == 0)
		reverse_rotate_both_stacks(stack_a, stack_b, cheapest_node);
	align_stacks_for_push(stack_a, cheapest_node, 'a');
	align_stacks_for_push(stack_b, cheapest_node->target_node, 'b');
	push(stack_a, stack_b, 1);
}
