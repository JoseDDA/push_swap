/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:59:18 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/28 19:12:47 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sync_rrr(t_stack *stacks, size_t index)
{
	while (index > 0 && stacks->target_a[index] > 0)
	{
		rev_rot(stacks, 2);
		index--;
		stacks->target_a[index]--; // Update target index logically
	}
	while (index > 0)
	{
		rev_rot(stacks, 0);
		index = (index == 0) ? stacks->size_a - 1 : index - 1; // Circular update
	}
	while (stacks->target_a[index] > 0)
	{
		rev_rot(stacks, 1);
		stacks->target_a[index]--; // Update target index logically
	}
}


void	sync_rr(t_stack *stacks, size_t index)
{
	while (index > 0 && stacks->target_a[index] > 0)
	{
		//printf("sync_rr\n");
		//printf("Index en Stack move [%zu]\n", index);
		rot(stacks, 2);
		index--;
		stacks->target_a[index]--;
	}
	while (index > 0)
	{
		//printf( "sync_rr: rotating stack a\n");
		//printf("Index en Stack move [%zu]\n", index);
		rot(stacks, 0 ),
		index--;
	}
	while (stacks->target_a[index] > 0)
	{
		//printf("sync_rr: rotating stack b\n");
		//printf("Index en Stack move [%zu]\n", index);
		rot(stacks, 1);
		stacks->target_a[index]--;
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
		//printf("r_top: Rotating Stack A\n");
		//printf("Index en Stack move [%zu]\n", index);
		if (index < median_A)
			rot(stacks, 0);
		else
			rev_rot(stacks, 0);
		index--;
	}
	//printf("Target A %d\n", (int) stacks->target_a[index]);
	while (stacks->target_a[0] != stacks->target_a[index])
	{
		//printf("r_top: Rotating Stack B\n");
		//printf("Index en Stack move [%zu]\n", index);
		if (stacks->target_a[index] < median_B)
			rot(stacks, 1);
		else
			rev_rot(stacks, 1);
	}
}
