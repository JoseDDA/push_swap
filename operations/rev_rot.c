/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:30:35 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/24 12:05:49 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rot(t_stack *stacks, int move)
{
	if (move == 0)
	{
		rra(stacks);
		printf("rra\n");
	}
	else if (move == 1)
	{
		rrb(stacks);
		printf("rrb\n");
	}
	else
	{
		rra(stacks);
		rrb(stacks);
		printf("rrr\n");
	}
}

void	rra(t_stack *stacks)
{
	int		temp;
	size_t	i;

	if (!stacks || stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[stacks->size_a - 1];
	i = stacks->size_a - 1;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
}

void	rrb(t_stack *stacks)
{
	int		temp;
	size_t	i;

	if (!stacks || stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[stacks->size_b - 1];
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
}
