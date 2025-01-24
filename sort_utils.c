/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:41:02 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/22 18:03:12 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

size_t	find_index(t_stack *stacks, int min_value)
{
	size_t	i;
	int		*stack;

	i = 0;
	stack = stacks->stack_a;
	while (i < stacks->size_a)
	{
		if (stack[i] == min_value)
			return (i);
		i++;
	}
	return (i);
}

int	find_min(t_stack *stacks)
{
	size_t	i;
	int	min_value;

	i = 0;
	min_value = INT_MAX;
	while (i < stacks->size_a -1)
	{
		if (stacks->stack_a[i] < min_value)
			min_value = stacks->stack_a[i];
		i++;
	}
	return (min_value);
}

int	find_max(t_stack *stacks)
{
	size_t	i;
	int	max_value;

	i = 0;
	max_value = INT_MIN;
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] > max_value)
			max_value = stacks->stack_a[i];
		i++;
	}
	return (max_value);
}
