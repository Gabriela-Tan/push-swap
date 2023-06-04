/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:27:30 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/30 10:33:00 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **head_a, t_list **head_b, int flag)
{
	t_list	*temp;

	if (*head_b == NULL)
		return ;
	temp = *head_a;
	*head_a = *head_b;
	*head_b = (*head_b)->next;
	(*head_a)->next = temp;
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **head_a, t_list **head_b, int flag)
{
	t_list	*temp;

	if (*head_a == NULL)
		return ;
	temp = *head_b;
	*head_b = *head_a;
	*head_a = (*head_a)->next;
	(*head_b)->next = temp;
	if (flag == 1)
		write(1, "pb\n", 3);
}
