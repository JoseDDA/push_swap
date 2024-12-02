/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:38:49 by jdorazio          #+#    #+#             */
/*   Updated: 2024/12/02 09:34:49 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int	size;
	
	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack -> next;
		size++;
	}
	return (size);
}
/*
	Returns a pointer to the last node in the stack.
	- If the stack is empty, returns NULL.
*/
t_stack	*get_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	//printf("Last node %d\n", stack->value);
	return (stack);
}

t_stack	*highest_node_value(t_stack *stack)
{
	t_stack	*highest_node;
	t_stack	*curr;

	if (!stack)
		return (NULL);
	highest_node = NULL;
	curr = stack;
	while (curr)
	{
		if (!highest_node || curr->value > highest_node->value)
			highest_node = curr;
		curr = curr->next;
	}
	return (highest_node);	
}

t_stack *lowest_node_value(t_stack *stack)
{
	t_stack	*lowest_node;
	t_stack	*curr;

	if (!stack)
		return (NULL);
	lowest_node = NULL;
	curr = stack;
	while (curr)
	{
		if (!lowest_node || curr->value < lowest_node->value)
			lowest_node = curr;
		curr = curr->next;
	}
	return (lowest_node);
}

/*
	Ensure the lowest value node in the stack is moved to the top.

	Steps:
	1. Identify the lowest value node using `lowest_node_value`.
	2. Use `finish_rot` to bring the lowest node to the top of the stack.

	Note: This function assumes the stack is partially sorted or being finalized 
	      for operations requiring the lowest value on top.
*/
void	bring_lowest_to_top(t_stack **stack)
{
	t_stack	*lowest_node;

	if (!stack)
		return;
	lowest_node = lowest_node_value(*stack);
	if (!lowest_node)
		return ;
	align_stacks_for_push(stack, lowest_node, 'a');
}
