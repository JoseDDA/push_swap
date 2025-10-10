/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:31:30 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/05 09:40:29 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack *stacks)
{
	int		target;
	int		*s_a;
	size_t	i;
	size_t	j;

	i = 0;
	s_a = stacks->stack_a;
	while (i < stacks->size_b)
	{
		target = -1;
		j = 0;
		while (j < stacks->size_a)
		{
			if (stacks->stack_b[i] < s_a[j]
				&& (target == -1 || s_a[j] < s_a[target]))
				target = j;
			j++;
		}
		if (target == -1)
			target = find_index(s_a, stacks->size_a, find_min(stacks));
		stacks->target_b[i] = target;
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
