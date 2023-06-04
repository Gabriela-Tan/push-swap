/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:19:05 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/31 15:06:24 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **head_a)
{
	if (ft_find_max(*head_a) == (*head_a)->number)
	{
		ra(head_a, 1);
		if (!ft_is_sorted(*head_a))
			sa(head_a, 1);
	}
	else if (ft_find_min(*head_a) == (*head_a)->number)
	{
		rra(head_a, 1);
		sa(head_a, 1);
	}
	else
	{
		if (ft_index(*head_a, ft_find_max(*head_a)) == 1)
			rra(head_a, 1);
		else
			sa(head_a, 1);
	}
}

void	ft_sort(t_list **stack_a)
{
	t_list	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_list_size(*stack_a) == 2)
		sa(stack_a, 1);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = ft_index(*stack_a, ft_find_min(*stack_a));
		if (i < ft_list_size(*stack_a) - i)
		{
			while ((*stack_a)->number != ft_find_min(*stack_a))
				ra(stack_a, 1);
		}
		else
		{
			while ((*stack_a)->number != ft_find_min(*stack_a))
				rra(stack_a, 1);
		}
	}
}

t_list	*ft_sort_b(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (!ft_is_sorted(*stack_a) && ft_list_size(*stack_a) > 3)
		pb(stack_a, &stack_b, 1);
	if (!ft_is_sorted(*stack_a) && ft_list_size(*stack_a) > 3)
		pb(stack_a, &stack_b, 1);
	if (!ft_is_sorted(*stack_a) && ft_list_size(*stack_a) > 3)
		ft_sort_more_b(stack_a, &stack_b);
	if (!ft_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

void	ft_sort_more_b(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*current;

	while (!ft_is_sorted(*stack_a) && ft_list_size(*stack_a) > 3)
	{
		current = *stack_a;
		i = ft_check_moves_b(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == moves_rarb_b(*stack_a, *stack_b, current->number))
				i = rarb_pb(stack_a, stack_b, current->number);
			else if (i == moves_rrarrb_b(*stack_a, *stack_b, current->number))
				i = rrarrb_pb(stack_a, stack_b, current->number);
			else if (i == moves_rarrb_b(*stack_a, *stack_b, current->number))
				i = rarrb_pb(stack_a, stack_b, current->number);
			else if (i == moves_rrarb_b(*stack_a, *stack_b, current->number))
				i = rrarb_pb(stack_a, stack_b, current->number);
			else
				current = current->next;
		}
	}
}

t_list	**ft_sort_a(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*current;

	while (*stack_b)
	{
		current = *stack_b;
		i = ft_check_moves_a(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == moves_rarb_a(*stack_a, *stack_b, current->number))
				i = rarb_pa(stack_a, stack_b, current->number);
			else if (i == moves_rarrb_a(*stack_a, *stack_b, current->number))
				i = rarrb_pa(stack_a, stack_b, current->number);
			else if (i == moves_rrarrb_a(*stack_a, *stack_b, current->number))
				i = rrarrb_pa(stack_a, stack_b, current->number);
			else if (i == moves_rrarb_a(*stack_a, *stack_b, current->number))
				i = rrarb_pa(stack_a, stack_b, current->number);
			else
				current = current->next;
		}
	}
	return (stack_a);
}
