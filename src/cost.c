/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:03:24 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/05 10:01:28 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_r_cost(size_t i, size_t size, size_t median)
{
	if (i <= median)
		return (i);
	return (size - i);
}

int	ft_rr_rrr_cost(size_t i, size_t target, t_stack *stacks, int is_rr)
{
	int	total_moves;

	if (is_rr && i <= (stacks->size_a / 2) && target <= (stacks->size_a / 2))
	{
		total_moves = i - target;
		if (total_moves < 0)
			total_moves *= -1;
		if (i < target)
			return (total_moves += i);
		else
			return (total_moves += target);
	}
	else if (!is_rr && i > (stacks->size_a / 2)
		&& target > (stacks->size_b / 2))
	{
		total_moves = (stacks->size_a - i) - (stacks->size_b - target);
		if (total_moves < 0)
			total_moves *= -1;
		if ((stacks->size_a - i) < (stacks->size_b - target))
			return (total_moves += stacks->size_a - i);
		else
			return (total_moves += stacks->size_b - target);
	}
	return (INT_MAX);
}

void	ft_calculate_cost(t_stack *stacks)
{
	size_t	i;
	size_t	a_size;
	size_t	b_size;

	a_size = stacks->size_a;
	b_size = stacks->size_b;
	i = 0;
	while (i < stacks->size_a)
	{
		stacks->cost[i] = ft_r_cost(i, a_size, (a_size / 2))
			+ ft_r_cost(stacks->target_a[i], b_size, (b_size / 2));
		stacks->cost_rr[i] = ft_rr_rrr_cost(i, stacks->target_a[i], stacks, 1);
		stacks->cost_rrr[i] = ft_rr_rrr_cost(i, stacks->target_a[i], stacks, 0);
		i++;
	}
}

size_t	find_lowest_index(int *cost_array, size_t size)
{
	size_t	cheapest_index;
	size_t	i;

	i = 0;
	cheapest_index = size;
	while (i < size)
	{
		if (cheapest_index == size
			|| cost_array[i] < cost_array[cheapest_index])
			cheapest_index = i;
		i++;
	}
	return (cheapest_index);
}

size_t	pick_cheapest(t_stack *stacks)
{
	size_t	cost;
	size_t	rr_cost;
	size_t	rrr_cost;

	cost = find_lowest_index(stacks->cost, stacks->size_a);
	rr_cost = find_lowest_index(stacks->cost_rr, stacks->size_a);
	rrr_cost = find_lowest_index(stacks->cost_rrr, stacks->size_a);
	if (stacks->cost[cost] <= stacks->cost_rr[rr_cost]
		&& stacks->cost[cost] <= stacks->cost_rrr[rrr_cost])
		return (stacks->rr_rrr = 0, cost);
	else if (stacks->cost_rr[rr_cost] <= stacks->cost[cost]
		&& stacks->cost_rr[rr_cost] <= stacks->cost_rrr[rrr_cost])
		return (stacks->rr_rrr = 1, rr_cost);
	else
		return (stacks->rr_rrr = 2, rrr_cost);
}
