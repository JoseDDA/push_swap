/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:12:15 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/24 12:10:19 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	while (i < stacks->size_a - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->size_b - 1] = temp;
}

void	rot(t_stack *stacks, int move)
{
	if (move == 0)
	{
		ra(stacks);
		printf("ra\n");
	}
	else if (move == 1) 
	{
		rb(stacks);
		printf("rb\n");
	}
	else
	{
		ra(stacks);
		rb(stacks);
		printf("rr\n");
	}
}
