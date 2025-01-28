/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:59:18 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/28 18:55:46 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	r_top_b(t_stack *stacks, size_t index)
{
	size_t	median_A;
	size_t	median_B;
	size_t	rot_count_B;
	size_t	rot_count_A;

	median_A = stacks->size_a / 2;
	median_B = stacks->size_b / 2;

	// Calculate rotations needed for stack_b
	if (index < median_B)
		rot_count_B = index; // Rotations to bring index to the top
	else
		rot_count_B = stacks->size_b - index; // Reverse rotations to bring index to the top

	// Calculate rotations needed for target in stack_a
	if (stacks->target_b[index] < median_A)
		rot_count_A = stacks->target_b[index]; // Rotations for target
	else
		rot_count_A = stacks->size_a - stacks->target_b[index]; // Reverse rotations for target
	//printf("Index %d | Median B %d | Rot_count A: %d | Rot_count B: %d\n", (int) index, (int) median_B, (int) rot_count_A, (int) rot_count_B);
	// Rotate both stacks simultaneously
	while (rot_count_B > 0 && rot_count_A > 0)
	{
		if (index <= median_B && stacks->target_b[index] <= median_A)
			rot(stacks, 2); // Rotate both stacks
		else
			rev_rot(stacks, 2); // Reverse rotate both stacks
		rot_count_B--;
		rot_count_A--;
	}

	// Rotate stack_b independently
	while (rot_count_B > 0)
	{
		if (index < median_B)
			rot(stacks, 1);
		else
			rev_rot(stacks, 1);
		rot_count_B--;
	}

	// Rotate stack_a independently
	while (rot_count_A > 0)
	{
		if (stacks->target_b[index] < median_A)
			rot(stacks, 0);
		else
			rev_rot(stacks, 0);
		rot_count_A--;
	}
}
