/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:34:45 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/06 13:34:54 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_handler(int error_code, t_stack *stacks, char **arr)
{
	if (error_code == 0)
		exit(0);
	else if (error_code == 1)
		free_stacks(stacks);
	else if (error_code == 2)
		free_array(arr);
	else if (error_code == 3)
	{
		free_stacks(stacks);
		free_array(arr);
	}
	else if (error_code == 4)
		write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_stacks(t_stack *stacks)
{
	free(stacks->stack_a);
	free(stacks->target_a);
	free(stacks->stack_b);
	free(stacks->target_b);
	free(stacks->cost);
	free(stacks->cost_rr);
	free(stacks->cost_rrr);
	free(stacks);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
