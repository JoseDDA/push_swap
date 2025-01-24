/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:09:27 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/24 17:11:47 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stacks;

	stacks = ft_calloc(1, sizeof(t_stack));
	if (!stacks)
		exit_handler(1);
	check_init_stacks(ac, av, stacks);

	// Debug: Imprimir el estado inicial de stack_a y stack_b
	// printf("Initial Stack A:\n");
	// for (size_t i = 0; i < stacks->size_a; i++)
	// 	printf("stack_a[%zu] = %d\n", i, stacks->stack_a[i]);
	// printf("\nInitial Stack B:\n");
	// for (size_t i = 0; i < stacks->size_b; i++)
	// 	printf("stack_b[%zu] = %d\n", i, stacks->stack_b[i]);
	// printf("\n");

	if (!sorted(stacks))
	{
		//printf("Stack is not sorted. Proceeding to sort...\n");
		if (stacks->size_a == 2)
		{
		//	printf("Swapping stack_a (2 elements)...\n");
			swap(stacks, 0);
		}
		else if (stacks->size_a == 3)
		{
		//	printf("Sorting stack_a (3 elements)...\n");
			sort_three(stacks);
		}
		else if (is_sorted_circular(stacks))
		{
		//	printf("Sorting stack_a circularly...\n");
			sort_circular_stack(stacks);
		}
		else
		{
		//	printf("start sorting stack A using stack B\n");
			sort_stacks(stacks);
		
		}
	}
	



// Debug: Imprimir el estado final de stack_a y stack_b
	// printf("\nFinal Stack A:\n");
	// for (size_t i = 0; i < stacks->size_a; i++)
	// 	printf("stack_a[%zu] = %d\n", i, stacks->stack_a[i]);
	// printf("\nFinal Stack B:\n");
	// for (size_t i = 0; i < stacks->size_b; i++)
	// 	printf("stack_b[%zu] = %d\n", i, stacks->stack_b[i]);
	// printf("\n");

	// Liberar memoria al final
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks->target_a);
	free(stacks->target_b);
	free(stacks->cost);
	free(stacks->cost_rr);
	free(stacks->cost_rrr);
	free(stacks);
	return (0);
}

