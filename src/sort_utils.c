/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:33:08 by jdorazio          #+#    #+#             */
/*   Updated: 2024/11/25 23:06:51 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_max(t_stack *src)
{
	t_stack	*max_node;

	if (!src)
		return (NULL);
	max_node = src;
	while (src != NULL)
	{
		if (src -> value > max_node -> value)
			max_node = src;
		src = src -> next;
	}
	return (max_node);
}

int	ft_min(t_stack *src)
{
	int	min;

	min = src -> value;
	while (src != NULL)
	{
		if (src -> value < min)
			min = src -> value;
		src = src -> next;
	}
	return (min);
}
