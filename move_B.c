/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:31:30 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/24 17:14:49 by jdorazio         ###   ########.fr       */
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
			(target == (int) stacks->size_a || stacks->stack_a[j] < 	stacks->stack_a[target]))
				target = j;
			j++;
		}
		stacks->target_b[i] = target;
		//printf("Set_Target_B: Value %d[%zu] -> Target %zu\n",	stacks->stack_b[i], i, stacks->target_b[i]);
		i++;
	}
}

void	move_cheapest_b(t_stack *stacks)
{
	size_t	cheapest_index;

	//printf("Setting target B \n");
	set_target_b(stacks);
	ft_calculate_cost_b(stacks);
	cheapest_index = pick_cheapest_b(stacks);
	//printf("Cheapes iNdex %d[%d]\n", (int) stacks->stack_b[cheapest_index], (int) cheapest_index);
	//printf("r_top B\n");
	r_top_b(stacks, cheapest_index);


}
