/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:50:43 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/31 15:03:47 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_moves_a(t_list *stack_a, t_list *stack_b)
{
	int		moves;
	t_list	*current;

	current = stack_b;
	moves = moves_rrarrb_a(stack_a, stack_b, stack_b->number);
	while (current)
	{
		if (moves > moves_rarb_a(stack_a, stack_b, current->number))
			moves = moves_rarb_a(stack_a, stack_b, current->number);
		if (moves > moves_rrarrb_a(stack_a, stack_b, current->number))
			moves = moves_rrarrb_a(stack_a, stack_b, current->number);
		if (moves > moves_rarrb_a(stack_a, stack_b, current->number))
			moves = moves_rarrb_a(stack_a, stack_b, current->number);
		if (moves > moves_rrarb_a(stack_a, stack_b, current->number))
			moves = moves_rrarb_a(stack_a, stack_b, current->number);
		current = current->next;
	}
	return (moves);
}

int	moves_rarb_a(t_list *stack_a, t_list *stack_b, int number)
{
	int	moves;

	moves = ft_index_stack_a(stack_a, number);
	if (moves < ft_index(stack_b, number))
		moves = ft_index(stack_b, number);
	return (moves);
}

int	rarb_pa(t_list **stack_a, t_list **stack_b, int push)
{
	while ((*stack_b)->number != push && ft_index_stack_a(*stack_a, push) > 0)
		rr(stack_a, stack_b, 1);
	while ((*stack_b)->number != push)
		rb(stack_b, 1);
	while (ft_index_stack_a(*stack_a, push) > 0)
		ra(stack_a, 1);
	pa(stack_a, stack_b, 1);
	return (-1);
}

int	moves_rrarrb_a(t_list *stack_a, t_list *stack_b, int number)
{
	int	moves;

	moves = 0;
	if (ft_index_stack_a(stack_a, number))
		moves = ft_list_size(stack_a) - ft_index_stack_a(stack_a, number);
	if ((moves < (ft_list_size(stack_b) - ft_index(stack_b, number)))
		&& ft_index(stack_b, number))
		moves = ft_list_size(stack_b) - ft_index(stack_b, number);
	return (moves);
}

int	rrarrb_pa(t_list **stack_a, t_list **stack_b, int push)
{
	while ((*stack_b)->number != push && ft_index_stack_a(*stack_a, push) > 0)
		rrr(stack_a, stack_b, 1);
	while ((*stack_b)->number != push)
		rrb(stack_b, 1);
	while (ft_index_stack_a(*stack_a, push) > 0)
		rra(stack_a, 1);
	pa(stack_a, stack_b, 1);
	return (-1);
}
