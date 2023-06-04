/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:50:43 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/31 15:04:48 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_moves_b(t_list *stack_a, t_list *stack_b)
{
	int		moves;
	t_list	*current;

	current = stack_a;
	moves = moves_rrarrb_b(stack_a, stack_b, stack_a->number);
	while (current)
	{
		if (moves > moves_rarb_b(stack_a, stack_b, current->number))
			moves = moves_rarb_b(stack_a, stack_b, current->number);
		if (moves > moves_rrarrb_b(stack_a, stack_b, current->number))
			moves = moves_rrarrb_b(stack_a, stack_b, current->number);
		if (moves > moves_rarrb_b(stack_a, stack_b, current->number))
			moves = moves_rarrb_b(stack_a, stack_b, current->number);
		if (moves > moves_rrarb_b(stack_a, stack_b, current->number))
			moves = moves_rrarb_b(stack_a, stack_b, current->number);
		current = current->next;
	}
	return (moves);
}

int	moves_rarb_b(t_list *stack_a, t_list *stack_b, int number)
{
	int	moves;

	moves = ft_index_stack_b(stack_b, number);
	if (moves < ft_index(stack_a, number))
		moves = ft_index(stack_a, number);
	return (moves);
}

int	rarb_pb(t_list **stack_a, t_list **stack_b, int push)
{
	while ((*stack_a)->number != push && ft_index_stack_b(*stack_b, push) > 0)
		rr(stack_a, stack_b, 1);
	while ((*stack_a)->number != push)
		ra(stack_a, 1);
	while (ft_index_stack_b(*stack_b, push) > 0)
		rb(stack_b, 1);
	pb(stack_a, stack_b, 1);
	return (-1);
}

int	moves_rrarrb_b(t_list *stack_a, t_list *stack_b, int number)
{
	int	moves;

	moves = 0;
	if (ft_index_stack_b(stack_b, number))
		moves = ft_list_size(stack_b) - ft_index_stack_b(stack_b, number);
	if ((moves < (ft_list_size(stack_a) - ft_index(stack_a, number)))
		&& ft_index(stack_a, number))
		moves = ft_list_size(stack_a) - ft_index(stack_a, number);
	return (moves);
}

int	rrarrb_pb(t_list **stack_a, t_list **stack_b, int push)
{
	while ((*stack_a)->number != push && ft_index_stack_b(*stack_b, push) > 0)
		rrr(stack_a, stack_b, 1);
	while ((*stack_a)->number != push)
		rra(stack_a, 1);
	while (ft_index_stack_b(*stack_b, push) > 0)
		rrb(stack_b, 1);
	pb(stack_a, stack_b, 1);
	return (-1);
}
