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

/*
	Validates the overall syntax of the input array.
	Returns 1 if valid, 0 otherwise.
	Checks for: valid numbers, multiple zeros, and duplicates.
*/
int	validate_input (char **av)// Valid = 1  | Unvalid = 0
{
	int	i;
	int	c_zeros;

	i = 0;
	c_zeros = 0;
	while (av[i])
	{
		if (!is_valid_number(av[i]))
			return (write(1, "Not a Number\n", 13), 2);
		c_zeros += multiple_zeros(av[i]);
		i++;
	}
	if (c_zeros > 1)
		return (write(1, "Multiple 0\n", 11), 2);
	if (!has_duplicates(av))
		return (write(1, "Duplicates\n", 11), 2);
	return (1); 
}

/*
	Checks if a string represents a valid number (with an optional sign).
	Returns 1 if valid, 0 otherwise.
*/
int	is_valid_number(char *av)// Valid = 1  | Unvalid = 0
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

/*
	Checks if a string contains only one Zero(0) either with + or - sign.
	Returns 1 if true, 0 otherwise.
*/
int	multiple_zeros(char *av)// Valid = 1  | Unvalid = 0
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

/*
	Checks if the input array contains duplicate numbers.
	Returns 1 if no duplicates, 0 otherwise.
*/
int	has_duplicates(char **av)// Valid = 1  | Unvalid = 0
{
	int	i;
	int	j;
	long int num_i;
	long int num_j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while(av[j])
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
