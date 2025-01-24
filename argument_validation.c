/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:57:16 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/23 14:05:07 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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
		parse_av = ft_split(av[1], ' ');
	else
		parse_av = av + 1;
	if (!parse_av || !*parse_av)
		exit_handler(1);
	return (parse_av);
}

void	validate_and__init(char **parse_argument, t_stack *stacks)
{
	long	num;
	int		i;

	// Validate
	if (!validate_input(parse_argument))
		exit_handler(1);
	// Count Elements
	stacks->size_a = 0;
	while (parse_argument[stacks->size_a])
		stacks->size_a++;
	stacks->stack_a = ft_calloc(stacks->size_a, sizeof(int));
	if (!stacks->stack_a)
		exit_handler(1);
	i = 0;
	// Convert To Int a Save in Array
	while (parse_argument[i])
	{
		num = ft_atol(parse_argument[i]);
		if (num < INT_MIN || num > INT_MAX)
			exit_handler(1);
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
	if (!stacks->stack_b || !stacks->target_a || !stacks->target_b || 
	!stacks->cost || !stacks->cost_rr || !stacks->cost_rrr)
		exit_handler(1);
}

void	check_init_stacks(int ac, char **av, t_stack *stacks)
{
	char	**parse_argument;

	// Step 1: parse arguments
	parse_argument = parse_av(ac, av); 
	// Step 2: validate arguments
	validate_and__init(parse_argument, stacks);
	// Step 3: Reserve memory for the other arrays
	allocate_memory(stacks); 

}
