/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:16:16 by jdorazio          #+#    #+#             */
/*   Updated: 2024/11/01 00:16:16 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack *sA;
	t_stack *sB;

	/* Handle input count errors. Argument count must be > 2 and 
	the second input must not be empty
	Handle both cases of input: cl arguments or a string
		If it's a string we need to split the substrings
	*/
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (printf("Error: Check Inputed Arguments\n"), 1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	/* Declare pointers to two linked list
		Set both pointers to NULL to avoid behaviour and indicate 
		we're starting with empty stacks	
	*/
	sA = NULL; 
	sB = NULL;
	/* Initialize Stack `a`by appending each input number as a node */
	ft_stack_init(&sA, argv + 1);
	while (sA != NULL)
	{
		printf("Num %d\n", sA->value);
		sA = sA -> next;
	}
	/* Check if Stack A is sorted
		If not sorted, implement sorting algorithm
			Check for 2 numberes
				If so, simply swap the numbers
			Check for 3 numberes
				If so, implement our simple'sort three' algo
			Check if the stack has more than 3 numbers
				If so, Implement our Turk Algo
	*/
	// check if Stack A is already sorted.
	// if (sorted(&sA))
	// 	return (printf("already sorted \n"), 0);
	// if (ft_stack_size(sA) == 2)
	// 	ft_swap(&sA);
	// if (ft_stack_size(sA) == 3)
	// 	ft_sort_three(&sA);

	return (0);
}

