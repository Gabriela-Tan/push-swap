/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:31:18 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/30 10:35:24 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **head_a, int flag)
{
	t_list	*temp;
	int		i;

	if (*head_a && (*head_a)->next)
	{
		i = 0;
		temp = *head_a;
		while ((*head_a)->next)
		{
			*head_a = (*head_a)->next;
			i++;
		}
		(*head_a)->next = temp;
		while (i > 1)
		{
			temp = temp->next;
			i--;
		}
		temp->next = NULL;
		if (flag == 1)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_list **head_b, int flag)
{
	t_list	*temp;
	int		i;

	if (*head_b && (*head_b)->next)
	{
		i = 0;
		temp = *head_b;
		while ((*head_b)->next)
		{
			*head_b = (*head_b)->next;
			i++;
		}
		(*head_b)->next = temp;
		while (i > 1)
		{
			temp = temp->next;
			i--;
		}
		temp->next = NULL;
		if (flag == 1)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **head_a, t_list **head_b, int flag)
{
	rra(head_a, 0);
	rrb(head_b, 0);
	if (flag == 1)
		write(1, "rrr\n", 4);
}
