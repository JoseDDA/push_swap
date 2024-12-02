/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:04:38 by jdorazio          #+#    #+#             */
/*   Updated: 2024/12/02 09:49:29 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
	# define  PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int		value;
	int		index;
	int		push_cost;
	int		median;// True = 1 | False = 0
	int		cheapest;// True = 1 | False = 0
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}t_stack;

// INPUT PARSING
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);


// STACK INIT 
void	init_stack(t_stack **stack_a, char **av);
long	ft_atol(const char *nptr);
void	append_node(t_stack **stack_a, int num);

// INPUT VALIDATION
int		validate_input(char **av);
int		is_valid_number(char *av);
int		ft_isdigit(int c);
int		sign(char argv);
int		multiple_zeros(char *av);
int		has_duplicates(char **av);

// HANDLE ERRORS
void	clear_stack(t_stack **stack);
void	handle_error(t_stack **a);

// SORT
int		sorted(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_large_stack(t_stack **stack_a, t_stack **stack_b);

// SORT UTILS
int	ft_stack_size(t_stack *stack);
t_stack	*get_last_node(t_stack *stack);
t_stack	*highest_node_value(t_stack *stack);
t_stack *lowest_node_value(t_stack *stack);
void	bring_lowest_to_top(t_stack **stack);

// OPERATIONS
void	push(t_stack **src_stack, t_stack **dest_stack, int	select);
void	swap(t_stack **node, int select); // WORKING PERFECTLY
void	ss(t_stack **sA, t_stack **sB);
void	rot(t_stack **stack, int select);
void	rr(t_stack **sA, t_stack **sB);
void	rev_rot(t_stack **stack, int select);
void	rrr(t_stack **sA, t_stack **sB);

// STACK A PREPARATION
void	prepare_stack_a_for_sorting(t_stack *stack_a, t_stack *stack_b);

// STACK A PREPARATION UTILS
void	assign_stack_index_and_median(t_stack *stack);
void	assign_targets_in_B(t_stack *stack_a, t_stack *stack_b);
void	calculate_push_cost(t_stack *stack_a, t_stack *stack_b);
int		shared_cost(int cost_a, int cost_b);
void	set_cheapest(t_stack *stack);

// PUSH A to B
void	push_A_to_B(t_stack **stack_a, t_stack **stack_b);
void	rotate_both_stacks(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);
void	reverse_rotate_both_stacks (t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node);
void	align_stacks_for_push (t_stack **stack, t_stack *cheapest_node, char name);
t_stack	*get_cheapest(t_stack *stack);

// PUSH A to B
void	push_B_to_A (t_stack **stack_a, t_stack **stack_b);
void	prepare_stack_b_for_sorting(t_stack *stack_a, t_stack *stack_b);
void	assign_targets_in_A(t_stack *stack_a, t_stack *stack_b);

#endif
