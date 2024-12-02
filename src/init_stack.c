/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:34:42 by jdorazio          #+#    #+#             */
/*   Updated: 2024/12/02 09:34:32 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

/*
	Converts a string to a long integer.
	Handles optional leading whitespace, '+' or '-' sign, and numeric digits.
	Stops processing at the first non-digit character.
*/

long	ft_atol(const char *nptr)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((9 <= *nptr && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		sign = -sign;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		num = (num * 10) + (*nptr - '0');
		nptr++;
	}
	return (sign * num);
}

/*
	Appends a new node to the end of the stack.
	- If the stack is empty, initializes the stack with the new node.
	- Otherwise, traverses to the last node and appends the new node.
	Exits on memory allocation failure.
*/
void	append_node(t_stack **stack_a, int num)
{
	t_stack	*new_node;
	t_stack	*curr;

	if (!stack_a)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		handle_error(stack_a);
	new_node->value = num;
	new_node->push_cost = 0;
	new_node->cheapest = 0;
	new_node->next = NULL;
	if (!*stack_a)
	{
		*stack_a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		curr = *stack_a;
		while (curr->next)
			curr = curr->next;
		curr->next =new_node;
		new_node->prev = curr;
	}
}
/*
	Initializes the stack with values from the input array.
	- Validates the input syntax using `valid_syntax`.
	- Converts each string to an integer (using `ft_atol`) and appends it to the stack.
	- Frees the stack and exits on any error (invalid syntax, out-of-range values, or allocation failure).
*/

void	init_stack(t_stack **stack_a, char **av)
{
	int		i;
	long	num;

	if (!validate_input(av)) // NOT True = 1 -> free_erros | NOT False = 0->continue
		handle_error(stack_a);
	i = 0;
	while (av[i])
	{
		num = ft_atol(av[i]);
		if (num > INT_MAX || INT_MIN > num)
		{
			printf("Error ATOL\n");
			handle_error(stack_a);
		}
		append_node(stack_a, (int) num);
		i++;
	}
}
