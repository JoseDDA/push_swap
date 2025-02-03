/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:04:38 by jdorazio          #+#    #+#             */
/*   Updated: 2025/01/29 23:18:45 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	size_t	size_a;
	int		*stack_a;
	size_t	*target_a;
	size_t	size_b;
	int		*stack_b;
	size_t	*target_b;
	int		*cost;
	int		*cost_rr;
	int		*cost_rrr;
	size_t	rr_rrr; // funciona como un flag. 0 = rot, 1 = rot both, 2 = rev rot both
}			t_stack;

// ##----## Program ##----##

int	main(int ac, char **av);

// ##----## Functions ##----##


// ###-- exit_handler.c --###
void	exit_handler(int num);
// ##-----------------------------------------------##


// ##-- argument_validation --##
void	check_init_stacks(int ac, char **av, t_stack *stacks);
void	allocate_memory(t_stack *stacks);
char	**parse_av(int ac, char **av);
long	ft_atol(const char *nptr);
// ##-- argument_validation_utils --##
int	has_duplicates(char **av);
int	sign(char argv);
int	multiple_zeros(char *av);
int	is_valid_number(char *av);
int	validate_input(char **av);
// ##-----------------------------------------------##


// ##-- sort --##
int		sorted(t_stack *t_stacks);
void	sort_three(t_stack *stacks);
int		is_sorted_circular(t_stack *stacks);
void	sort_circular_stack(t_stack *stacks);
void	sort_stacks(t_stack *stacks);
// ##-----------------------------------------------##

// ##-- sort_utils --##
size_t	find_index(int *stack, size_t size, int value);
int	find_min(t_stack *stacks);
int	find_max(int *stacks, size_t size);
// ##-----------------------------------------------##

// ##-- Sort Stackas Algorithm --##
void	move_cheapest(t_stack *stacks);
void	set_target_a(t_stack *stacks);
// ##-----------------------------------------------##


// ##-- Costs --##
size_t	pick_cheapest(t_stack *stacks);
void	ft_calculate_cost(t_stack *stacks);
int		ft_r_cost(size_t i, size_t size, size_t median);
int		ft_rr_rrr_cost(size_t i, size_t size_A, size_t size_B, size_t target, int is_rr);
size_t	find_lowest_index(int *cost_array, size_t size);
// ##-----------------------------------------------##

// ##-- Stack Moves --##
void	sync_rr_rrr(t_stack *stacks, size_t index, size_t rr_or_rrr);
void	r_top(t_stack *stacks, size_t index, size_t median_a, size_t median_b);
// ##-----------------------------------------------##


// ##-- Move B --## RENAME 
void	set_target_b(t_stack *stacks);
void	move_cheapest_b(t_stack *stacks);


void	ft_calculate_cost_b(t_stack *stacks);
size_t	find_lowest_index(int *cost_array, size_t size);
size_t	pick_cheapest_b(t_stack *stacks);
void	r_top_b(t_stack *stacks, size_t index);


// ##-- OPERATIONS --##
// ----------------------
// ##---- push ----##
void	push(t_stack *stacks, int to);
void	pa(t_stack *stacks);
void	pb(t_stack *stacks);
// ##---- swap ----##
void	swap(t_stack *stacks, int move);
void	sa(t_stack *stacks);
void	sb(t_stack *stacks);
// ##---- rot ----##
void	rot(t_stack *stacks, int move);
void	ra(t_stack *stacks);
void	rb(t_stack *stacks);
// ##---- rev rot ----##
void	rev_rot(t_stack *stacks, int move);
void	rra(t_stack *stacks);
void	rrb(t_stack *stacks);
// ##------------------------------------##


#endif
