/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:31:30 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/28 18:38:10 by jdorazio         ###   ########.fr       */
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
		target = stacks->size_a;
		j = 0;
		while (j < stacks->size_a)
		{
			if (stacks->stack_b[i] < stacks->stack_a[j]  && 
			(target == (int) stacks->size_a || stacks->stack_a[j] < stacks->stack_a[target]))
				target = j;
			j++;
		}
		if (target == (int) stacks->size_a)
			target = find_index(stacks, find_max(stacks));
		else
			stacks->target_b[i] = target;
		//printf("DEBUG: B[%zu] = %d -> Target A[%d] = %d\n", i, stacks->stack_b[i], target, stacks->stack_a[target]);
		i++;
	}
	//printf("\n");
}


void	move_cheapest_b(t_stack *stacks)
{
	size_t	cheapest_index;

	//printf("Setting target B \n");
	set_target_b(stacks);
	ft_calculate_cost_b(stacks);
	cheapest_index = pick_cheapest_b(stacks);
	//printf("\n");
	//printf("DEBUG: Cheapest in Stack B: %d[%zu]\n", stacks->stack_b[cheapest_index], cheapest_index);
	//printf("DEBUG: Target in Stack A: %d[%zu]\n", stacks->stack_a[stacks->target_b[cheapest_index]], stacks->target_b[cheapest_index]);
	//printf("\n");
	
	r_top_b(stacks, cheapest_index);
}

