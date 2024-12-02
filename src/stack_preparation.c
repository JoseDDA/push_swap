/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_preparation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorazio <jdorazio@student.42.madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:13:26 by jdorazio          #+#    #+#             */
/*   Updated: 2024/12/02 09:45:54 by jdorazio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

/* 
Prepares stack A for sorting by:
1. Assigning index and median values to nodes in both stacks.
2. Finding target nodes in stack B for each node in stack A.
3. Calculating the cost of moving each node.
4. Identifying the cheapest node in stack A to move.
*/
void	prepare_stack_a_for_sorting(t_stack *stack_a, t_stack *stack_b)
{
	assign_stack_index_and_median(stack_a);
	assign_stack_index_and_median(stack_b);
	assign_targets_in_B(stack_a, stack_b);
	calculate_push_cost(stack_a, stack_b);
	set_cheapest(stack_a);
}
