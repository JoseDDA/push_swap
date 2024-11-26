/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:54:22 by jdorazio          #+#    #+#             */
/*   Updated: 2024/11/25 21:42:33 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (src == NULL)
	{
		printf("Error: Head Is NULL");
		return;
	}
	temp = (*src) -> next;
	(*src) -> next = *dest;
	*dest = *src;
	*src = temp;
}
