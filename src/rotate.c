/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:46:26 by jdorazio          #+#    #+#             */
/*   Updated: 2024/11/25 21:44:43 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_rotate(t_stack **src)
{
	t_stack	*temp;
	t_stack *last;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src) -> next;
	(*src) -> prev = NULL;
	last = *src;
	while (last -> next != NULL)
		last = last -> next;
	last -> next = temp; 
	temp -> prev = last;
	temp -> next = NULL;
}

void	ft_reverse_rotate(t_stack **src)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*src == NULL)
		return ;
	last = *src;
	while (last -> next != NULL)
	{
		second_last = last;
		last = last -> next;
	}
	second_last -> next = NULL;
	last -> next = *src;
	(*src) -> prev = last;
	last -> prev = NULL;
	*src = last;
}
