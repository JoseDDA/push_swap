/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:31:30 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/29 22:21:21 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack *stacks)
{
	int		target;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stacks->size_b)
	{
		target = -1;
		j = 0;
		while (j < stacks->size_a)
		{
			if (stacks->stack_b[i] < stacks->stack_a[j]  && 
			(target == -1 || stacks->stack_a[j] < stacks->stack_a[target]))
				target = j;
			j++;
		}
		if (target == -1)
			target = find_index(stacks->stack_a, stacks->size_a, find_max(stacks->stack_a, stacks->size_a) );
		stacks->target_b[i] = target;
		//printf("Stack B: Value %d[%zu] -> Target A %d[%zu]\n", stacks->stack_b[i], i, stacks->stack_a[target], stacks->target_b[i]);
		i++;
	}
}


void	move_cheapest_b(t_stack *stacks)
{
	size_t	cheapest_index;

	set_target_b(stacks);
	ft_calculate_cost_b(stacks);
	cheapest_index = pick_cheapest_b(stacks);
	r_top_b(stacks, cheapest_index);
}

