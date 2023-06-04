/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:58:21 by gabriela          #+#    #+#             */
/*   Updated: 2023/06/04 14:21:46 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_list **stack)
{
	t_list	*following;

	if (stack == NULL)
		return ;
	while (*stack)
	{
		following = (*stack)->next;
		(*stack)->number = 0;
		free(*stack);
		*stack = following;
	}
}

void	ft_free_array(char **array)
{
	int		i;
	char	*str;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		str = array[i];
		free(str);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}
