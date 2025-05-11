/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:09:27 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/23 14:47:32 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stacks;

	stacks = ft_calloc(1, sizeof(t_stack));
	if (!stacks)
		exit_handler(0, NULL, NULL);
	if (ac == 1)
		exit_handler(0, NULL, NULL);
	check_init_stacks(ac, av, stacks);
	if (!stacks)
		free_stacks(stacks);
	if (!sorted(stacks))
	{
		if (stacks->size_a == 2)
			swap(stacks, 0);
		else if (stacks->size_a == 3)
			sort_three(stacks);
		else if (is_sorted_circular(stacks))
			sort_circular_stack(stacks);
		else
			sort_stacks(stacks);
	}
	free_stacks(stacks);
	return (0);
}
// Debug: Imprimir el estado final de stack_a y stack_b

	// printf("\nFinal Stack A:\n");
	// for (size_t i = 0; i < stacks->size_a; i++)
	// 	printf("stack_a[%zu] = %d\n", i, stacks->stack_a[i]);
	// printf("\nFinal Stack B:\n");
	// for (size_t i = 0; i < stacks->size_b; i++)
	// 	printf("stack_b[%zu] = %d\n", i, stacks->stack_b[i]);
	// printf("\n");
