/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:12:15 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/05 09:43:11 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot(t_stack *stacks, int move)
{
	if (move == 0)
	{
		ra(stacks);
		write(1, "ra\n", 3);
	}
	else if (move == 1)
	{
		rb(stacks);
		write(1, "rb\n", 3);
	}
	else
	{
		ra(stacks);
		rb(stacks);
		write(1, "rr\n", 3);
	}
}

void	ra(t_stack *stacks)
{
	int		temp;
	size_t	i;

	if (!stacks || stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->size_a - 1] = temp;
}

void	rb(t_stack *stacks)
{
	int		temp;
	size_t	i;

	if (!stacks || stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->size_b - 1] = temp;
}
