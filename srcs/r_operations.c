/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:33:48 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/30 10:32:20 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **head_a, int flag)
{
	t_list	*temp;

	if (*head_a && (*head_a)->next)
	{
		temp = *head_a;
		*head_a = ft_list_last(*head_a);
		(*head_a)->next = temp;
		*head_a = temp->next;
		temp->next = NULL;
		if (flag == 1)
			write(1, "ra\n", 3);
	}
}

void	rb(t_list **head_b, int flag)
{
	t_list	*temp;

	if (*head_b && (*head_b)->next)
	{
		temp = *head_b;
		*head_b = ft_list_last(*head_b);
		(*head_b)->next = temp;
		*head_b = temp->next;
		temp->next = NULL;
		if (flag == 1)
			write(1, "rb\n", 3);
	}
}

void	rr(t_list **head_a, t_list **head_b, int flag)
{
	ra(head_a, 0);
	rb(head_b, 0);
	if (flag == 1)
		write(1, "rr\n", 3);
}
