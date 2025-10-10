/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:06:33 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/05 14:26:54 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *stacks)
{
	size_t	i;

	if (!stacks)
		return (0);
	i = 0;
	while (i < stacks->size_a -1)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_three(t_stack *stacks)
{
	int	max_value;

	if (!stacks || stacks->size_a > 3)
		return ;
	max_value = find_max(stacks->stack_a, stacks->size_a);
	if (max_value == stacks->stack_a[0])
		rot(stacks, 0);
	else if (max_value == stacks->stack_a[1])
		rev_rot(stacks, 0);
	if (stacks->stack_a[0] > stacks->stack_a[1])
		swap(stacks, 0);
}

int	is_sorted_circular(t_stack *stacks)
{
	size_t	i;
	size_t	min_index;
	size_t	size_a;

	i = 0;
	size_a = stacks->size_a;
	min_index = find_index(stacks->stack_a, size_a, find_min(stacks));
	while (i < size_a - 1)
	{
		if (stacks->stack_a[(min_index + i) % size_a]
			> stacks->stack_a[(min_index + i + 1) % size_a])
			return (0);
		i++;
	}
	return (1);
}

void	sort_circular_stack(t_stack *stacks)
{
	size_t	size_a;
	size_t	min_index;
	int		min_value;
	size_t	rot_cost;
	size_t	rr_cost;

	size_a = stacks->size_a;
	min_value = find_min(stacks);
	min_index = find_index(stacks->stack_a, size_a, min_value);
	rot_cost = min_index;
	rr_cost = size_a - min_index;
	if (rot_cost < rr_cost)
		while (find_index(stacks->stack_a, size_a, min_value) != 0)
			rot(stacks, 0);
	else
		while (find_index(stacks->stack_a, size_a, min_value) != 0)
			rev_rot(stacks, 0);
}

void	sort_stacks(t_stack *stacks)
{
	if (stacks->size_a > 3 && !sorted(stacks))
		push(stacks, 1);
	if (is_sorted_circular(stacks) && !sorted(stacks))
		sort_circular_stack(stacks);
	if (stacks->size_a > 3 && !sorted(stacks))
		push(stacks, 1);
	if (is_sorted_circular(stacks) && !sorted(stacks))
		sort_circular_stack(stacks);
	while (stacks->size_a > 3 && !sorted(stacks))
	{
		move_cheapest(stacks);
		push(stacks, 1);
		if (is_sorted_circular(stacks))
			sort_circular_stack(stacks);
	}
	sort_three(stacks);
	while (stacks->size_b)
	{
		move_cheapest_b(stacks);
		push(stacks, 0);
	}
	sort_circular_stack(stacks);
}
