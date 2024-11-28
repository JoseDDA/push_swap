/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:54:22 by jdorazio          #+#    #+#             */
/*   Updated: 2024/11/26 22:51:47 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Swap the first two elements of a stack
void	swap_a(t_stack **sa)
{
	int		temp;

	if (*sa == NULL || (*sa) -> next == NULL)
	{
		printf("Error: swaping less than 2 elements\n");
		return;
	}
	temp = (*sa) -> value;
	(*sa) -> value = (*sa) -> next -> value;
	(*sa) -> next -> value = temp;
	write(1, "sa\n", 3);
}

// Push First Element from Source Stack to Destine Stack
void	push_a(t_stack **sa, t_stack **sb)
{
	t_stack	*temp;

	if (sa == NULL)
	{
		printf("Error: Head Is NULL");
		return;
	}
	temp = (*sa) -> next;
	(*sa) -> next = *sb;
	*sb = *sa;
	*sa = temp;
	write(1, "pa\n", 3);

}

// Rotate First Element -> Means Last Element Becomes the First
void rot_a(t_stack **sa)
{
	t_stack	*temp;
	t_stack *last;

	if (*sa == NULL)
		return ;
	temp = *sa;
	*sa = (*sa) -> next;
	(*sa) -> prev = NULL;
	last = *sa;
	while (last -> next != NULL)
		last = last -> next;
	last -> next = temp; 
	temp -> prev = last;
	temp -> next = NULL;
	write(1, "ra\n", 3);
}

// Reverse Rotate First Element -> Means First Element Becomes the Last
void	rev_rot_a(t_stack **sa)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*sa == NULL)
		return ;
	last = *sa;
	while (last -> next != NULL)
	{
		second_last = last;
		last = last -> next;
	}
	second_last -> next = NULL;
	last -> next = *sa;
	(*sa) -> prev = last;
	last -> prev = NULL;
	*sa = last;
	write(1, "rra\n", 3);
}

// Swap the first two elements of a stack
void	swap_b(t_stack **sb)
{
	int		temp;

	if (*sb == NULL || (*sb) -> next == NULL)
	{
		printf("Error: swaping less than 2 elements\n");
		return;
	}
	temp = (*sb) -> value;
	(*sb) -> value = (*sb) -> next -> value;
	(*sb) -> next -> value = temp;
	write(1, "sb\n", 3);
}

// Push First Element from Source Stack to Destine Stack
void	push_b(t_stack **sb, t_stack **sa)
{
	t_stack	*temp;

	if (sb == NULL)
	{
		printf("Error: Head Is NULL");
		return;
	}
	temp = (*sb) -> next;
	(*sb) -> next = *sa;
	*sa = *sb;
	*sb = temp;
	write(1, "pb\n", 3);

}

// Rotate First Element -> Means Last Element Becomes the First
void rot_b(t_stack **sb)
{
	t_stack	*temp;
	t_stack *last;

	if (*sb == NULL)
		return ;
	temp = *sb;
	*sb = (*sb) -> next;
	(*sb) -> prev = NULL;
	last = *sb;
	while (last -> next != NULL)
		last = last -> next;
	last -> next = temp; 
	temp -> prev = last;
	temp -> next = NULL;
	write(1, "rb\n", 3);
}

// Reverse Rotate First Element -> Means First Element Becomes the Last
void	rev_rot_b(t_stack **sb)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*sb == NULL)
		return ;
	last = *sb;
	while (last -> next != NULL)
	{
		second_last = last;
		last = last -> next;
	}
	second_last -> next = NULL;
	last -> next = *sb;
	(*sb) -> prev = last;
	last -> prev = NULL;
	*sb = last;
	write(1, "rrb\n", 3);
}
