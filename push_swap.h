/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 05:55:29 by jdorazio          #+#    #+#             */
/*   Updated: 2024/11/04 05:55:29 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
// # include <aio.h>
# include <stdlib.h>
# include <limits.h>


typedef struct s_stack
{
	void			*content;
	struct s_stack	*next;
} t_stack;


// FUNCTION TO VALIDATE INPUT
int	ft_strlen(char *s);
int	ft_isdigit(int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	input_validation(char **av);
int	check_if_number(char *av);
int	check_multiple_zeros(char *av);
int	check_duplicates(char **av);

// ALGORITHM PART

#endif
