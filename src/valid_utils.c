/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:53:54 by jdorazio          #+#    #+#             */
/*   Updated: 2024/11/19 18:53:54 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sign(char argv)
{
	return (argv == '-' || argv == '+');
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
