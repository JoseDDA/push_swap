/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:41:02 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/05 09:44:00 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_index(int *stack, size_t size, int value)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == value)
			return (i);
		i++;
	}
	return (i);
}

int	find_min(t_stack *stacks)
{
	size_t	i;
	int		min_value;

	i = 0;
	min_value = INT_MAX;
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] < min_value)
			min_value = stacks->stack_a[i];
		i++;
	}
	return (min_value);
}

int	find_max(int *stack, size_t size)
{
	size_t	i;
	int		max_value;

	i = 0;
	max_value = INT_MIN;
	while (i < size)
	{
		if (stack[i] > max_value)
			max_value = stack[i];
		i++;
	}
	return (max_value);
}
