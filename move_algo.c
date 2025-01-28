/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:19:52 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/28 19:14:51 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_stack *stacks)
{
	size_t	cheapest_index;

	//printf("Starting to Set target to Stack A\n");
	set_target_a(stacks);
	ft_calculate_cost(stacks);
	cheapest_index = pick_cheapest(stacks);
	//printf("Cheapest Index %d[%d]\n", (int) stacks->stack_a[cheapest_index], (int) cheapest_index);
	if (stacks->rr_rrr == 1)
	{
		//printf("\n sync_rr en move_cheapest\n");
		sync_rr(stacks, cheapest_index);
	}
	else if (stacks-> rr_rrr == 2)
	{
		//printf("\n sync_rrr en move_cheapest\n");
		sync_rrr(stacks, cheapest_index);
	}
	else
	{

		//printf("\n R_rot en move_cheapest\n");
		r_top(stacks, cheapest_index);
	}
}


void	set_target_a(t_stack *stacks)
{
	int		target;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stacks->size_a)
	{
		target = stacks->size_b;
		j = 0;
		while (j < stacks->size_b)
		{
			if (stacks->stack_a[i] < stacks->stack_b[j] && 
			(target == (int)stacks->size_b || stacks->stack_b[j] < stacks->stack_b[target]))
				target = j;
			j++;
		}
		stacks->target_a[i] = target;
	// printf("Set_Target_A: Value %d[%zu] -> Target %zu\n", stacks->stack_a[i], i, stacks->target_a[i]);
		i++;
	}
}


