/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:36:38 by jdorazio          #+#    #+#             */
/*   Updated: 2024/12/02 09:26:32 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * clear_stack - Frees all nodes in the stack and resets the pointer to NULL.
 * stack: A double pointer to the stack to be cleared.
 */

void	clear_stack(t_stack **stack) //Define a function to free a stack if there are errors
{
	t_stack	*tmp; //To store the next node in the stack before the current node is freed, because once a node is freed, you can't access its next pointer
	t_stack	*current;

	if (!stack) //Check for an empty stack
		return ;
	current = *stack;
	while (current) //As long as a node exist in the stack
	{
		tmp = current->next; //Assign to `tmp` the pointer to the next node
		current->value = 0; //Assigning the node to `0` before freeing is not strictly necessary but it can help catch potential bugs such as memory-leaks and improve debugging
		free(current); //Free the current node, deallocating the memory occupied by that node
		current = tmp; //Assign `tmp` as the current first node
	}
	*stack = NULL;
}

/**
 * handle_error - Frees the stack and exits the program with an error message.
 * stack: A double pointer to the stack to be freed.
 */
void	handle_error (t_stack **a) //Define a function that, upon encountering a unique error, to free the stack and print an error message
{
	clear_stack(a);
	write(1, "Error\n", 6);
	exit(1);
}
