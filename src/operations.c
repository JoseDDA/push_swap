/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:54:22 by jdorazio          #+#    #+#             */
/*   Updated: 2024/12/02 09:30:31 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* 
	First Element from Source Stack to Destine Stack
	Source Stack can be either A or B
	select = 0 -> swap_A
	select = 1 -> swap_1
*/
void	push(t_stack **src_stack, t_stack **dest_stack, int	select)
{
	t_stack	*pushed_node;

	if (!src_stack || !*src_stack)
		return;
	pushed_node = *src_stack;
	*src_stack = (*src_stack)->next;
	if (*src_stack)
		(*src_stack)->prev = NULL;
	if (!dest_stack)
		return ; 
	pushed_node->next = *dest_stack;
	if (*dest_stack)
		(*dest_stack)->prev = pushed_node;
	*dest_stack = pushed_node;
	pushed_node->prev = NULL;
	if (select == 0)
		write(1, "pa\n", 3);
	else if (select == 1)
		write(1, "pb\n", 3);
	else;
}

/*
	Swap Works equally for both stacks. 
	Only difference is the print
*/
void	swap(t_stack **node, int select)
{
	int		temp;
	t_stack	*curr;

	if (!node || !*node || !(*node)->next)
		return;
	curr = *node;
	temp = curr->value;
	curr->value = curr->next->value;
	curr->next->value = temp;
	if (select == 0)
		write(1, "sa\n", 3);
	else if (select == 1)
		write(1, "sb\n", 3);
	else;
}

 void	ss(t_stack **sA, t_stack **sB)
 {
	if (!sA || !sB || !*sA || !*sB)
		return;
	swap(sA, 2);
	swap(sB, 2);
	write(1, "ss\n", 3);
 }



// Rotate First Element -> Means Last Element Becomes the First
void	rot(t_stack **stack, int select)
{
	t_stack *last;
	t_stack	*new_head;

	if (!stack ||!*stack || !(*stack)->next)
		return ;
	last = get_last_node(*stack);
	if (!last)
		return;
	new_head = (*stack)->next;
	new_head->prev = NULL;
	last->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = last;
	*stack = new_head;
	if (select == 0)
			write(1, "ra\n", 3);
	else if (select == 1)
			write(1, "rb\n", 3);
	else;
}

 void	rr(t_stack **sA, t_stack **sB)
 {
	if (!sA || !sB)
		return;
	rot(sA, 2);
	rot(sB, 2);
	write(1, "rr\n", 3);
 }
// Reverse Rotate First Element -> Means First Element Becomes the Last
void	rev_rot(t_stack **stack, int select)
{
	t_stack	*last;

	if (!stack || !*stack ||!(*stack)->next)
		return;
	last = get_last_node(*stack);
	if (!last || !last->prev)
		return;
	if (last->prev)
		last->prev->next = NULL;
	last->next = *stack; //Assign to its own `next` attribute as the top node of the stack
	*stack = last; //Update the current last node of the stack
	if (last->next)
		last->next->prev = last;
	if (select == 0)
		write(1, "rra\n", 4);
	else if (select == 1)
		write(1, "rrb\n", 4);
	else;
}

 void	rrr(t_stack **sA, t_stack **sB)
 {
	if (!sA || !sB)
		return;
	rev_rot(sA, 2);
	rev_rot(sB, 2);
	write(1, "rrr\n", 4);
 }
