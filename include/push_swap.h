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
	int				above_median; // True = 1, False = 0
	int				cheapest; // True = 1, False = 0
	struct s_stack	*target_node;
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
void	ft_stack_init(t_stack **sA, char **argv);
 long	ft_atol(const char *nptr);
void	append_node(t_stack **sA, int num);

// Allowed Operations for STACK A
void	swap_a(t_stack **sa);
void	push_a(t_stack **sa, t_stack **sb);
void rot_a(t_stack **sa);
void	rev_rot_a(t_stack **sa);
// Allowed Operations for STACK B
void	swap_b(t_stack **sb);
void	push_b(t_stack **sb, t_stack **sa);
void rot_b(t_stack **sb);
void	rev_rot_b(t_stack **sb);


// Algorithm Utils
int		ft_stack_size(t_stack *src);
int		sorted(t_stack *sA);
void	sort_three(t_stack **sA);
t_stack	*ft_max(t_stack *src);
t_stack	*ft_min(t_stack *src);
t_stack	*ft_lastnode(t_stack *node);


// Algor
void	sort_stacks(t_stack **sA, t_stack **sB);
void	find_index_median(t_stack *sA);
void	find_target_A(t_stack *sA, t_stack *sB);
void	find_cost(t_stack *sA, t_stack *sB);
void	find_cheapest(t_stack *sA);
void	init_nodes_A(t_stack *sA, t_stack *sB);
t_stack	*get_cheapest(t_stack *src);
void	move_node_A_to_B(t_stack **sA, t_stack **sB);
void	rot_both(t_stack *sA, t_stack *sB, t_stack *cheapest_node);
o
#endif
