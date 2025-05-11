/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validation_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:34:52 by jdorazio          #+#    #+#             */
/*   Updated: 2025/02/06 13:35:49 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_input(char **av)
{
	int	i;
	int	c_zeros;

	i = 0;
	c_zeros = 0;
	while (av[i])
	{
		if (!is_valid_number(av[i]))
			exit_handler(4, NULL, NULL);
		c_zeros += multiple_zeros(av[i]);
		i++;
	}
	if (c_zeros > 1)
		exit_handler(4, NULL, NULL);
	if (!has_duplicates(av))
		exit_handler(4, NULL, NULL);
	return (1);
}

int	sign(char argv)
{
	return (argv == '-' || argv == '+');
}

int	is_valid_number(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '\0')
		return (0);
	if (sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

int	multiple_zeros(char *av)
{
	int	i;

	i = 0;
	if (sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	has_duplicates(char **av)
{
	int			i;
	int			j;
	long int	num_i;
	long int	num_j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			num_i = ft_atol(av[i]);
			num_j = ft_atol(av[j]);
			if (num_i == num_j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
