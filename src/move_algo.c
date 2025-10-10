/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:19:52 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/05 09:38:08 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_stack *stacks)
{
	size_t	cheapest_index;
	size_t	median_a;
	size_t	median_b;

	median_a = stacks->size_a / 2;
	median_b = stacks->size_b / 2;
	set_target_a(stacks);
	ft_calculate_cost(stacks);
	cheapest_index = pick_cheapest(stacks);
	if (stacks->rr_rrr == 1)
		sync_rr_rrr(stacks, cheapest_index, 1);
	else if (stacks-> rr_rrr == 2)
		sync_rr_rrr(stacks, cheapest_index, 2);
	else
		r_top(stacks, cheapest_index, median_a, median_b);
}

void	set_target_a(t_stack *stacks)
{
	int		target;
	size_t	i;
	size_t	j;
	size_t	size_b;
	int		*s_b;

	i = 0;
	s_b = stacks->stack_b;
	size_b = stacks->size_b;
	while (i < stacks->size_a)
	{
		j = 0;
		target = -1;
		while (j < size_b)
		{
			if (stacks->stack_a[i] > s_b[j]
				&& (target == -1 || s_b[j] > s_b[target]))
				target = j;
			j++;
		}
		if (target == -1)
			target = find_index(s_b, size_b, find_max(s_b, size_b));
		stacks->target_a[i] = target;
		i++;
	}
}
