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

#include "push_swap.h"

//VALIDATION
//	TRUE = 1, FALSE = 0
int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// only accepts one sign 
int	check_sign(char av)
{
	return (av == '-' || av == '+');
}

int	check_if_number(char *av)
{
	int	i;

	i = 0;
	if (check_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

int	input_validation(char **av)
{
	int i;
	int	zero_count;

	i = 1;
	while (av[i])
	{
		if (!check_if_number(av[i]))
			return (0);
		zero_count += check_multiple_zeros(av[i]);
		i++;
	}
	if (zero_count > 1)
		return (0);
	// Check Duplicates
	if (check_duplicates(av))
		return (0);
	return (1);
}

int	check_multiple_zeros(char *av)
{
	int	i;

	i = 0;
	if (check_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	check_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strncmp(av[i], av[j], ft_strlen(av[i])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	while (s[i])
		i++;
	return (i);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}


int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (!input_validation(av))
		return (0);
}

