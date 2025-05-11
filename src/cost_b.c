/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:03:24 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/05 10:04:33 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calculate_cost_b(t_stack *stacks)
{
	size_t	i;
	size_t	a_size;
	size_t	b_size;

	a_size = stacks->size_a;
	b_size = stacks->size_b;
	i = 0;
	while (i < b_size)
	{
		stacks->cost[i] = ft_r_cost(i, b_size, (b_size / 2))
			+ ft_r_cost(stacks->target_b[i], a_size, (a_size / 2));
		stacks->cost_rr[i] = ft_rr_rrr_cost(i, stacks->target_b[i], stacks, 1);
		stacks->cost_rrr[i] = ft_rr_rrr_cost(i, stacks->target_b[i], stacks, 0);
		i++;
	}
}

size_t	pick_cheapest_b(t_stack *stacks)
{
	size_t	cost;
	size_t	rr_cost;
	size_t	rrr_cost;

	cost = find_lowest_index(stacks->cost, stacks->size_b);
	rr_cost = find_lowest_index(stacks->cost_rr, stacks->size_b);
	rrr_cost = find_lowest_index(stacks->cost_rrr, stacks->size_b);
	if (stacks->cost[cost] <= stacks->cost_rr[cost]
		&& stacks->cost[cost] <= stacks->cost_rrr[rrr_cost])
		return (stacks->rr_rrr = 0, cost);
	else if (stacks->cost_rr[rr_cost] <= stacks->cost[cost]
		&& stacks->cost_rr[rr_cost] <= stacks->cost_rrr[rrr_cost])
		return (stacks->rr_rrr = 1, rr_cost);
	else
		return (stacks->rr_rrr = 2, rrr_cost);
}
