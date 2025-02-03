/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:03:24 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/29 23:41:18 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calculate_cost_b(t_stack *stacks)
{
	size_t	i;
	size_t	size_A;
	size_t	size_B;

	size_A = stacks->size_a;
	size_B = stacks->size_b;
	i = 0;
	while (i < stacks->size_b)
	{
		stacks->cost[i] = ft_r_cost(i, size_B, (size_B / 2)) + 
			ft_r_cost(stacks->target_b[i], size_A, (size_A / 2));
		
		stacks->cost_rr[i] = ft_rr_rrr_cost(i, size_B, size_A,
			 stacks->target_b[i], 1);
		
		stacks->cost_rrr[i] = ft_rr_rrr_cost(i, size_B, size_A,
			 stacks->target_b[i], 0);
	//printf("Cost %d[%zu]: Independent %d, rr: %d, rrr: %d\n",stacks->stack_b[i], i, stacks->cost[i], stacks->cost_rr[i], stacks->cost_rrr[i]);
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
	if (stacks->cost[cost] <= stacks->cost_rr[cost] && stacks->cost[cost] <= stacks->cost_rrr[rrr_cost])
		return (stacks->rr_rrr = 0, cost);
	else if (stacks->cost_rr[rr_cost] <= stacks->cost[cost] && stacks->cost_rr[rr_cost] <= stacks->cost_rrr[rrr_cost])
		return (stacks->rr_rrr = 1, rr_cost);
	else
		return (stacks->rr_rrr = 2, rrr_cost);
}
