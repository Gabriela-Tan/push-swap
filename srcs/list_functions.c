/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:24:23 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/30 10:32:47 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_add_back(t_list **list, t_list *new)
{
	if (list == NULL)
		return ;
	if (*list == NULL)
		*list = new;
	else
		(ft_list_last(*list))->next = new;
}

t_list	*ft_list_new(int number)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	new->number = number;
	new->next = NULL;
	return (new);
}

t_list	*ft_list_last(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	ft_list_size(t_list *list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}
