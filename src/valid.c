/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:49:30 by jdorazio          #+#    #+#             */
/*   Updated: 2024/11/20 10:49:30 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	valid_syntax(char *argv[])
{
	int	i;
	int	c_zeros;

	i = 1;
	c_zeros = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (printf("Not a Number\n"), 0); //invalid input
		c_zeros += mult_zeros(argv[i]);
		i++;
	}
	if (c_zeros > 1)
		return (printf("Multiple 0\n"), 0);
	if (!duplicated(argv))
		return (printf("Duplicates\n"), 0);
	return (1); //valid input
}

int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '\0')
		return (0);
	if (sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] && !ft_isdigit(argv[i]))
		return (0);
	return (1);
}

int	mult_zeros(char *argv)
{
	int	i;

	i = 0;
	if (sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	duplicated(char **argv)
{
	int	i;
	int	j;
	long int num_i;
	long int num_j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while(argv[j])
		{
			num_i = ft_atol(argv[i]);
			num_j = ft_atol(argv[j]);
			if (num_i == num_j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
