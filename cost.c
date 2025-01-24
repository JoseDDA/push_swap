/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:03:24 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/24 17:12:41 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Asignamos el costo de hacer una rotación cost
	Creamos una array de costo con base en el indice
*/
int	ft_r_cost(size_t i, size_t size, size_t median)
{
	if (i < median)
		return (i);
	return (size - i);
}

int	ft_rr_rrr_cost(size_t i, size_t size_A, size_t size_B, size_t target, int is_rr)
{
	size_t	median_A;
	size_t	median_B;

	median_A = size_A / 2;
	median_B = size_B / 2;
	if ((is_rr && i < median_A && target < median_B) ||
		(!is_rr && i >=median_A && target >= median_B))
	{
		if (is_rr)
		{
			if (i < target)
				return (i);
			else
				return (target);
		}
		else
		{
			if((size_A - i) < (size_B - target))
				return (size_A - i);
			else
				return (size_B - target);
		}
	}
	return (-1);

}

void	ft_calculate_cost(t_stack *stacks)
{
	size_t	i;
	size_t	size_A;
	size_t	size_B;

	size_A = stacks->size_a;
	size_B = stacks->size_b;
	i = 0;
	while (i < stacks->size_a)
	{
		stacks->cost[i] = ft_r_cost(i, size_A, (size_A / 2)) + 
			ft_r_cost(stacks->target_a[i], size_B, (size_B / 2));
		stacks->cost_rr[i] = ft_rr_rrr_cost(i, size_A, size_B,
			 stacks->target_a[i], 1);
		stacks->cost_rrr[i] = ft_rr_rrr_cost(i, size_A, size_B,
			 stacks->target_a[i], 0);
		//printf("Cost %d[%zu]: Independent %d, rr: %d, rrr: %d\n",stacks->stack_a[i], i, stacks->cost[i], stacks->cost_rr[i], stacks->cost_rrr[i]);
		i++;
	}
}

size_t	find_lowest_index(int *cost_array, size_t size)
{
	size_t	cheapest_index;
	size_t	i;

	i = 0;
	cheapest_index = 0;
	while (i < size)
	{
		if (cost_array[i] != -1 && (cheapest_index == size ||
			cost_array[i] < cost_array[cheapest_index]))
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

	// cost no retorna el costo, sino el indice del valor más bajo
	cost = find_lowest_index(stacks->cost, stacks->size_a);
	//printf("Cost: Cheapest %zu\n", cost);
	rr_cost = find_lowest_index(stacks->cost_rr, stacks->size_a);
	//printf("RR_Cost: Cheapest %zu\n", rr_cost);
	rrr_cost = find_lowest_index(stacks->cost_rrr, stacks->size_a);
	//printf("RRR_Cost: Cheapest %zu\n", rrr_cost);
	if (cost <= rr_cost && cost <= rrr_cost)
		return (stacks->rr_rrr = 0, cost);
	if (rr_cost < cost && rr_cost < rrr_cost)
		return (stacks->rr_rrr = 1, rr_cost);
	else
		return (stacks->rr_rrr = 2, rrr_cost);
}
