/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:19:52 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/29 22:05:26 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_stack *stacks)
{
	size_t	cheapest_index;

	// printf("Starting to Set target to Stack A\n");
	set_target_a(stacks);
	ft_calculate_cost(stacks);
	cheapest_index = pick_cheapest(stacks);
	// printf("Cheapest Number %d[%d] _> Targets %d[%d] \n ", (int) stacks->stack_a[cheapest_index], (int) cheapest_index, (int)stacks->stack_b[cheapest_index], (int)stacks->target_a[cheapest_index]);
	if (stacks->rr_rrr == 1)
	{
		// printf("\n sync_rr en move_cheapest\n");
		sync_rr_rrr(stacks, cheapest_index, 1);
	}
	else if (stacks-> rr_rrr == 2)
	{
		// printf("\n sync_rr_rrr_rrr en move_cheapest\n");
		sync_rr_rrr(stacks, cheapest_index, 2);
	}
	else
	{

		// printf("\n R_rot en move_cheapest\n");
		r_top(stacks, cheapest_index);
	}
}



void	set_target_a(t_stack *stacks)
{
	int		target;
	size_t	i;
	size_t	j;
	size_t	size_b;
	int		*s_B;

	i = 0;
	s_B = stacks->stack_b;
	size_b = stacks->size_b;
	while (i < stacks->size_a)
	{
		j = 0;
		target = -1;
		while (j < size_b)
		{
			if (stacks->stack_a[i] > s_B[j] && 
			(target == -1|| s_B[j] > s_B[target]))
				target = j;
			j++;
		}
		if (target == -1)
			target = find_index(s_B, size_b, find_max(s_B, size_b));
		stacks->target_a[i] = target;
	//printf("Stack A: Value %d[%zu] -> Target B %d[%zu]\n", stacks->stack_a[i], i, stacks->stack_b[target], stacks->target_a[i]);
		i++;
	}
}


