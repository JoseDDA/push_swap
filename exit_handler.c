/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:34:45 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/21 23:54:50 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"




void	exit_handler(int error_code)
{
	if (error_code)
		printf("Error\n");
	exit(error_code);
}
