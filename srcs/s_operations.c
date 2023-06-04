/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:55:19 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/30 10:32:30 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head_a, int flag)
{
	t_list	*temp;

	if (*head_a && (*head_a)->next)
	{
		temp = *head_a;
		*head_a = (*head_a)->next;
		temp->next = (*head_a)->next;
		(*head_a)->next = temp;
		if (flag == 1)
			write(1, "sa\n", 3);
	}
}

void	sb(t_list **head_b, int flag)
{
	t_list	*temp;

	if (*head_b && (*head_b)->next)
	{
		temp = *head_b;
		*head_b = (*head_b)->next;
		temp->next = (*head_b)->next;
		(*head_b)->next = temp;
		if (flag == 1)
			write(1, "sb\n", 3);
	}
}

void	ss(t_list **head_a, t_list **head_b, int flag)
{
	sa(head_a, 0);
	sb(head_b, 0);
	if (flag == 1)
		write(1, "ss\n", 3);
}
