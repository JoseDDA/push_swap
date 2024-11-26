/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:16:31 by jdorazio          #+#    #+#             */
/*   Updated: 2024/11/25 22:49:26 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Swap the first two elements of a stack
void	ft_swap(t_stack **src)
{
	int		temp;

	if (*src == NULL || (*src) -> next == NULL)
	{
		printf("Error: swaping less than 2 elements\n");
		return;
	}
	temp = (*src) -> value;
	(*src) -> value = (*src) -> next -> value;
	(*src) -> next -> value = temp;
}
