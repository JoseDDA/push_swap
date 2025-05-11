/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:57:05 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/05 09:41:39 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stacks, int to)
{
	if (to == 0)
	{
		pa(stacks);
		write(1, "pa\n", 3);
	}
	else if (to == 1)
	{
		pb(stacks);
		write(1, "pb\n", 3);
	}
}

void	pa(t_stack *stacks)
{
	size_t	i;
	int		temp;

	if (stacks->size_b == 0)
		return ;
	temp = stacks->stack_b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->size_b--;
	i = stacks->size_a;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
	stacks->size_a++;
}

void	pb(t_stack *stacks)
{
	size_t	i;
	int		temp;

	if (stacks->size_a == 0)
		return ;
	temp = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->size_a--;
	i = stacks->size_b;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
	stacks->size_b++;
}
