/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:30:35 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/05 09:42:22 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot(t_stack *stacks, int move)
{
	if (move == 0)
	{
		rra(stacks);
		write(1, "rra\n", 4);
	}
	else if (move == 1)
	{
		rrb(stacks);
		write(1, "rrb\n", 4);
	}
	else
	{
		rra(stacks);
		rrb(stacks);
		write(1, "rrr\n", 4);
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
