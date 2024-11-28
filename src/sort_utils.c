/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:33:08 by jdorazio          #+#    #+#             */
/*   Updated: 2024/11/26 23:36:28 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// This Function finds and Returns the Biggest Number in the Stack
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

// This Function finds and Returns the Smallest Number in the Stack
t_stack	*ft_min(t_stack *src)
{
	t_stack	*min_node;

	if (!src)
		return (NULL);
	min_node = src;
	while (src)
	{
		if (src -> value < min_node -> value)
			min_node = src;
		src = src -> next;
	}
	return (min_node);
}
// This function returns the last node of the stack
t_stack	*ft_lastnode(t_stack *node)
{
	t_stack	*lnode;

	if (!node)
		return (NULL);
	lnode = node;
	while (lnode)
		lnode = lnode -> next;
	return (lnode);
}

// int	find_index(t_stack *sa)
// {
// 	int	i;

// 	i = 0;
// 	while (sa)
// }
