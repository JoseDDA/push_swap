/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:13:28 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/05 09:47:35 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stacks, int move)
{
	if (move == 0)
	{
		sa(stacks);
		write(1, "sa\n", 3);
	}
	else if (move == 1)
	{
		sb(stacks);
		write(1, "sb\n", 3);
	}
	else
	{
		sa(stacks);
		sb(stacks);
		write(1, "ss\n", 3);
	}
}

void	sa(t_stack *stacks)
{
	int	temp;

	if (stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = temp;
}

void	sb(t_stack *stacks)
{
	int	temp;

	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = temp;
}
