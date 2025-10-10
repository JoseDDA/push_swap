/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:57:16 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/06 13:30:35 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	**parse_av(int ac, char **av)
{
	char	**parse_av;

	if (ac == 2)
	{
		parse_av = ft_split(av[1], ' ');
		if (!parse_av)
			return (NULL);
	}
	else
		parse_av = av + 1;
	if (!parse_av || !*parse_av)
	{
		if (ac == 2)
			exit_handler(0, NULL, parse_av);
	}
	return (parse_av);
}

void	validate_and__init(char **parse_argument, t_stack *stacks)
{
	long	num;
	int		i;

	if (!validate_input(parse_argument))
		exit_handler(3, stacks, parse_argument);
	stacks->size_a = 0;
	while (parse_argument[stacks->size_a])
		stacks->size_a++;
	stacks->stack_a = ft_calloc(stacks->size_a, sizeof(int));
	if (!stacks->stack_a)
		exit_handler(3, stacks, parse_argument);
	i = 0;
	while (parse_argument[i])
	{
		num = ft_atol(parse_argument[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			perror("Error\n");
			exit(1);
		}
		stacks->stack_a[i] = (int) num;
		i++;
	}
}

void	allocate_memory(t_stack *stacks)
{
	stacks->size_b = 0;
	stacks->stack_b = ft_calloc(stacks->size_a, sizeof(int));
	stacks->target_a = ft_calloc(stacks->size_a, sizeof(size_t));
	stacks->target_b = ft_calloc(stacks->size_a, sizeof(size_t));
	stacks->cost = ft_calloc(stacks->size_a, sizeof(int));
	stacks->cost_rr = ft_calloc(stacks->size_a, sizeof(int));
	stacks->cost_rrr = ft_calloc(stacks->size_a, sizeof(int));
	stacks->rr_rrr = 0;
	if (!stacks->stack_b || !stacks->target_a || !stacks->target_b
		|| !stacks->cost || !stacks->cost_rr || !stacks->cost_rrr)
		exit_handler(1, stacks, NULL);
}

void	check_init_stacks(int ac, char **av, t_stack *stacks)
{
	char	**parse_argument;

	parse_argument = parse_av(ac, av);
	validate_and__init(parse_argument, stacks);
	if (ac == 2)
		free_array(parse_argument);
	allocate_memory(stacks);
}
