/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:34:00 by jdorazio          #+#    #+#             */
/*   Updated: 2024/12/02 09:34:11 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

/*
	Sorts a stack of exactly three elements in ascending order.
	Does nothing if the stack has less than three elements.
*/
int	sorted(t_stack **stack)
{
	t_stack	*curr;

	if (!*stack)
		return (1);
	curr = *stack;
	while (curr->next)
	{
		if (curr->value > curr->next-> value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

/*
	Sorts a stack of exactly three elements in ascending order.
	Does nothing if the stack has less than three elements.
*/
void	sort_three(t_stack **stack)
{
	t_stack	*highest_node;

	if (!stack || !*stack || !(*stack)->next)
		return;
	highest_node = highest_node_value(*stack);
	if (!highest_node)
		return;
	if (highest_node == *stack)
		rot(stack, 0);
	else if (highest_node == (*stack)->next)
		rev_rot(stack, 0);
	if ((*stack)->value > (*stack)->next->value)
		swap(stack, 0);
}

/*
	Sorts a stack with more than three elements using a secondary stack.
	Steps:
	1. Push elements from stack_a to stack_b until only 3 remain.
	2. Sort the remaining 3 elements in stack_a.
	3. Push elements back from stack_b to stack_a in sorted order.
*/
void	sort_large_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	a_size; 

	a_size = ft_stack_size(*stack_a);
	if (a_size-- > 3 && !sorted(stack_a))
		push(stack_a, stack_b, 1); // Pushing to B
	if (a_size-- > 3 && !sorted(stack_a))
		push(stack_a, stack_b, 1); // Pushing to B
	while (a_size > 3 && !sorted(stack_a))
	{
		prepare_stack_a_for_sorting(*stack_a, *stack_b);
		push_A_to_B(stack_a, stack_b);
		a_size--;
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		prepare_stack_b_for_sorting(*stack_a, *stack_b);
		push_B_to_A(stack_a, stack_b);
	}
	bring_lowest_to_top(stack_a);
}
