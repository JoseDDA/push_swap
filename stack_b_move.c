/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:59:18 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/24 17:09:17 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_top_b(t_stack *stacks, size_t index)
{
	size_t	median_A;
	size_t	median_B;

	median_A = stacks->size_a / 2;
	median_B = stacks->size_b /2;
	while (index > 0 && stacks->stack_b[index] > 0)
	{
		if (index < median_B)
			rot(stacks, 1);
		else
			rev_rot(stacks, 1);
		index--;
	}
	while (stacks->target_b[index] > 0)
	{
		if (stacks->target_a[0] < median_A)
			rot(stacks, 0);
		else
			rev_rot(stacks, 0);
		stacks->target_b[index]--;
	}
}
