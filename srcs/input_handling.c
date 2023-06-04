/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:19:51 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/30 10:32:06 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index(t_list *stack, int number)
{
	int		i;

	i = 0;
	while (stack->number != number)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	ft_index_stack_b(t_list *stack_b, int number)
{
	int		i;
	t_list	*next;

	i = 1;
	if ((number > stack_b->number) && (number < ft_list_last(stack_b)->number))
		i = 0;
	else if ((number > ft_find_max(stack_b)) || (number < ft_find_min(stack_b)))
		i = ft_index(stack_b, ft_find_max(stack_b));
	else
	{
		next = stack_b->next;
		while ((stack_b->number < number) || (next->number > number))
		{
			stack_b = stack_b->next;
			next = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	ft_index_stack_a(t_list *stack_a, int number)
{
	int		i;
	t_list	*next;

	i = 1;
	if ((number < stack_a->number) && (number > ft_list_last(stack_a)->number))
		i = 0;
	else if ((number > ft_find_max(stack_a)) || (number < ft_find_min(stack_a)))
		i = ft_index(stack_a, ft_find_min(stack_a));
	else
	{
		next = stack_a->next;
		while ((stack_a->number > number) || (next->number < number))
		{
			stack_a = stack_a->next;
			next = stack_a->next;
			i++;
		}
	}
	return (i);
}
