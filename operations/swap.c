/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:13:28 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/22 17:29:44 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stacks, int move)
{
	if (move == 0)
	{
		sa(stacks);
		printf("sa\n");
	}
	else if (move == 1)
	{
		sb(stacks);
		printf("sb\n");
	}
	else
	{
		sa(stacks);
		sb(stacks);
		printf("ss\n");
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
