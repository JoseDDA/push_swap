/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:09:27 by jdorazio          #+#    #+#             */
/*   Updated: 2024/12/02 09:36:59 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split_av;

	split_av = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (write(1, "Not enough Arguments\n", 21), 1);
	if (ac == 2)
		split_av = ft_split(av[1], ' ');
	else
		split_av = av + 1;
	init_stack(&stack_a, split_av);
	if (!sorted(&stack_a))
	{
		//check first if Size = 2
		if (ft_stack_size(stack_a) == 2)
			swap(&stack_a, 0);
		// IF SIZE == 3
		else if (ft_stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_large_stack(&stack_a, &stack_b);
	}
	printf("\n");
    printf("Stack A\t | Stack B\n");
    printf("-------------------\n");
    while (stack_a || stack_b)
	{
        if (stack_a) {
            printf("%d\t\t", stack_a->value); // Print value from Stack A
            stack_a = stack_a->next;
        } else {
            printf("-\t\t"); // Placeholder for missing values in Stack A
        }

        if (stack_b) {
            printf("%d\n", stack_b->value); // Print value from Stack B
            stack_b = stack_b->next;
        } else {
            printf("-\n"); // Placeholder for missing values in Stack B
        }
    }
	return (0);
}
