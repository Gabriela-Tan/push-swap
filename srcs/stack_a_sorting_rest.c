/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_sorting_rest.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:50:43 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/31 15:03:18 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_rarrb_a(t_list *stack_a, t_list *stack_b, int number)
{
	int	moves;

	moves = 0;
	if (ft_index(stack_b, number))
		moves = ft_list_size(stack_b) - ft_index(stack_b, number);
	moves = ft_index_stack_a(stack_a, number) + moves;
	return (moves);
}

int	rarrb_pa(t_list **stack_a, t_list **stack_b, int push)
{
	while (ft_index_stack_a(*stack_a, push) > 0)
		ra(stack_a, 1);
	while ((*stack_b)->number != push)
		rrb(stack_b, 1);
	pa(stack_a, stack_b, 1);
	return (-1);
}

int	moves_rrarb_a(t_list *stack_a, t_list *stack_b, int number)
{
	int	moves;

	moves = 0;
	if (ft_index_stack_a(stack_a, number))
		moves = ft_list_size(stack_a) - ft_index_stack_a(stack_a, number);
	moves = ft_index(stack_b, number) + moves;
	return (moves);
}

int	rrarb_pa(t_list **stack_a, t_list **stack_b, int push)
{
	while (ft_index_stack_a(*stack_a, push) > 0)
		rra(stack_a, 1);
	while ((*stack_b)->number != push)
		rb(stack_b, 1);
	pa(stack_a, stack_b, 1);
	return (-1);
}
