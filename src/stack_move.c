/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:59:18 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/05 09:49:57 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sync_rr_rrr(t_stack *stacks, size_t index, size_t rr_or_rrr)
{
	int	a_index;
	int	b_index;

	a_index = stacks->stack_a[index];
	b_index = stacks->stack_b[stacks->target_a[index]];
	if (rr_or_rrr == 1)
	{
		while (a_index != stacks->stack_a[0] && stacks->stack_b[0] != b_index)
			rot(stacks, 2);
		while (a_index != stacks->stack_a[0])
			rot(stacks, 0);
		while (stacks->stack_b[0] != b_index)
			rot(stacks, 1);
	}
	else if (rr_or_rrr == 2)
	{
		while (a_index != stacks->stack_a[0] && stacks->stack_b[0] != b_index)
			rev_rot(stacks, 2);
		while (a_index != stacks->stack_a[0])
			rev_rot(stacks, 0);
		while (stacks->stack_b[0] != b_index)
			rev_rot(stacks, 1);
	}
}

void	r_top(t_stack *stacks, size_t index, size_t a_median, size_t b_median)
{
	int	a_index;
	int	b_index;

	a_index = stacks->stack_a[index];
	b_index = stacks->stack_b[stacks->target_a[index]];
	while (stacks->stack_a[0] != a_index)
	{
		if (index <= a_median)
			rot(stacks, 0);
		else
			rev_rot(stacks, 0);
	}
	while (stacks->stack_b[0] != b_index)
	{
		if (stacks->target_a[index] <= b_median)
			rot(stacks, 1);
		else
			rev_rot(stacks, 1);
	}
}

void	r_top_b(t_stack *stacks, size_t index)
{
	size_t	a_median;
	size_t	a_rot_count;

	a_median = stacks->size_a / 2;
	a_rot_count = stacks->target_b[index];
	if (stacks->target_b[index] >= a_median)
		a_rot_count = stacks->size_a - stacks->target_b[index];
	while (a_rot_count > 0)
	{
		if (stacks->target_b[index] < a_median)
			rot(stacks, 0);
		else
			rev_rot(stacks, 0);
		a_rot_count--;
	}
}
