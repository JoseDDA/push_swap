/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:59:18 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/02 20:25:13 by jdorazio         ###   ########.fr       */
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

void	r_top(t_stack *stacks, size_t index, size_t median_a, size_t median_b)
{
	int	value_A;
	int	value_B;

	value_A = stacks->stack_a[index];
	value_B = stacks->stack_b[stacks->target_a[index]];
	while (stacks->stack_a[0] != value_A)
	{
		if (index <= median_a)
			rot(stacks, 0);
		else
			rev_rot(stacks, 0);
	}
	while (stacks->stack_b[0] != value_B)
	{
		if (stacks->target_a[index] <= median_b)
			rot(stacks, 1);
		else
			rev_rot(stacks, 1);
	}
	

	// size_t	rot_count_a;
	// size_t	rot_count_b;

	// if (index == 0 && stacks->target_a[index] == 0)
	// 	return;
	// rot_count_a = index;
	// if (index > median_b)
	// 	rot_count_a = stacks->size_a - index;
	// rot_count_b = stacks->target_a[index];
	// if (stacks->target_a[index] > median_b)
	// 	rot_count_b = stacks->size_b - stacks->target_a[index];
	// while (rot_count_a > 0)
	// {
	// 	if (index <= median_a)
	// 		rot(stacks, 0);
	// 	else
	// 		rev_rot(stacks, 0);
	// 	rot_count_a--;
	// }
	// while (rot_count_b > 0)
	// {
	// 	if (stacks->target_a[index] <= median_b)
	// 		rot(stacks, 1);
	// 	else
	// 		rev_rot(stacks, 1);
	// 	rot_count_b--;
	// }
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
