/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:12:51 by jdorazio          #+#    #+#             */
/*   Updated: 2024/11/26 10:13:43 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(const char *nptr)
{
	long int	num;
	int			sign;

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

void	ft_stack_init(t_stack **sA, char **argv)
{
	int		i;
	long	int num;

	if (!valid_syntax(argv))
		exit(1);
	i = 0;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			printf("atoi failed\n");
			exit(1);
		}
		printf("%ld\n", num);
		append_node(sA, (int) num);
		i++;
	}
}

void	append_node(t_stack **sA, int num)
{
	t_stack	*curr;
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit(1);
	new_node -> value = num;
	new_node -> next = NULL;
	new_node -> cheapest = 0;
	if (!*sA)
		*sA = new_node;
	else
	{
		curr = *sA;
		while (curr -> next != NULL)
			curr = curr -> next;
		curr -> next = new_node;
	}
}

int	ft_stack_size(t_stack *src)
{
	int	size;

	size = 0;
	while (src != NULL)
	{
		size++;
		src = src -> next;
	}
	return (size);
}
