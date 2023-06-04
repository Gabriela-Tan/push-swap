/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_sorting_rest.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:50:43 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/31 15:04:17 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_rarrb_b(t_list *stack_a, t_list *stack_b, int number)
{
	int	moves;

	moves = 0;
	if (ft_index_stack_b(stack_b, number))
		moves = ft_list_size(stack_b) - ft_index_stack_b(stack_b, number);
	moves = ft_index(stack_a, number) + moves;
	return (moves);
}

int	rarrb_pb(t_list **stack_a, t_list **stack_b, int push)
{
	while ((*stack_a)->number != push)
		ra(stack_a, 1);
	while (ft_index_stack_b(*stack_b, push) > 0)
		rrb(stack_b, 1);
	pb(stack_a, stack_b, 1);
	return (-1);
}

int	moves_rrarb_b(t_list *stack_a, t_list *stack_b, int number)
{
	int	moves;

	moves = 0;
	if (ft_index(stack_a, number))
		moves = ft_list_size(stack_a) - ft_index(stack_a, number);
	moves = ft_index_stack_b(stack_b, number) + moves;
	return (moves);
}

int	rrarb_pb(t_list **stack_a, t_list **stack_b, int push)
{
	while ((*stack_a)->number != push)
		rra(stack_a, 1);
	while (ft_index_stack_b(*stack_b, push) > 0)
		rb(stack_b, 1);
	pb(stack_a, stack_b, 1);
	return (-1);
}
