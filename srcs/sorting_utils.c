/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:50:43 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/30 09:58:57 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *current_a)
{
	int	prior;

	prior = current_a->number;
	while (current_a != NULL)
	{
		if (prior > current_a->number)
			return (0);
		prior = current_a->number;
		current_a = current_a->next;
	}
	return (1);
}

int	ft_find_min(t_list *current_a)
{
	int		min;

	min = current_a->number;
	while (current_a)
	{
		if (current_a->number < min)
			min = current_a->number;
		current_a = current_a->next;
	}
	return (min);
}

int	ft_find_max(t_list *current_a)
{
	int		max;

	max = current_a->number;
	while (current_a)
	{
		if (current_a->number > max)
			max = current_a->number;
		current_a = current_a->next;
	}
	return (max);
}
