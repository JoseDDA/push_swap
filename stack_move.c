/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:59:18 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/29 23:01:18 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sync_rr_rrr(t_stack *stacks, size_t index, size_t rr_or_rrr)
{
	int	value_A;
	int	value_B;

	value_A = stacks->stack_a[index];
	value_B = stacks->stack_b[stacks->target_a[index]];

	if (rr_or_rrr == 1)
	{
		while (value_A != stacks->stack_a[0] && stacks->stack_b[0] != value_B)
			rot(stacks, 2);
		while (value_A != stacks->stack_a[0])
			rot(stacks, 0 );
		while (stacks->stack_b[0] != value_B)
			rot(stacks, 1);
	}
	else if (rr_or_rrr == 2)
	{
		while (value_A != stacks->stack_a[0] && stacks->stack_b[0] != value_B)
			rev_rot(stacks, 2);
		while (value_A != stacks->stack_a[0])
			rev_rot(stacks, 0 );
		while (stacks->stack_b[0] != value_B)
			rev_rot(stacks, 1);
	}
}

void	r_top(t_stack *stacks, size_t index)
{
	size_t	median_A;
	size_t	median_B;
	median_A = stacks->size_a / 2;
	median_B = stacks->size_b /2;

	while (index > 0)
	{
		if (index <= median_A)
			rot(stacks, 0);
		else
			rev_rot(stacks, 0);
		index--;
	}
	while (stacks->target_a[index] > 0)
	{
		if (stacks->target_a[index] <= median_B)
			rot(stacks, 1);
		else
			rev_rot(stacks, 1);
		stacks->target_a[index]--;
	}
}

void	r_top_b(t_stack *stacks, size_t index)
{
	size_t	median_A;
	size_t	rot_count_A;

	median_A = stacks->size_a / 2;
	rot_count_A = stacks->target_b[index]; 
	if (stacks->target_b[index] >= median_A)
		rot_count_A = stacks->size_a - stacks->target_b[index]; 
	while (rot_count_A > 0)
	{
		if (stacks->target_b[index] < median_A)
			rot(stacks, 0);
		else
			rev_rot(stacks, 0);
		rot_count_A--;
	}
}
