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

# include "../../libft/include/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>


typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct	s_tack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack; 


// Handle Errors


// FUNCTION TO VALIDATE INPUT
// Valid _ Utils
char	**ft_split(char const *s, char c);
int	valid_syntax(char *argv[]);
int	mult_zeros(char *argv);
int	duplicated(char **av);
int	is_number(char *argv);
int	sign(char argv);
int	ft_isdigit(int c);

// Stack Initialization
 long	ft_atol(const char *nptr);
void	append_node(t_stack **sA, int num);

// Allowed Operations - Commads
void	ft_swap(t_stack **src);
void	ft_push(t_stack **src, t_stack **dest);
void	ft_rotate(t_stack **src);
void	ft_reverse_rotate(t_stack **src);

// Algorithm
int	sorted(t_stack **src);
void	ft_sort_three(t_stack **src);
#endif
