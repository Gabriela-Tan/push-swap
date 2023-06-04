/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:00:15 by gabriela          #+#    #+#             */
/*   Updated: 2023/05/30 10:20:18 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;

	if (argc <= 1)
		return (0);
	stack_a = ft_create_stack_a(argc, argv);
	if (!stack_a || ft_is_dup(stack_a))
	{
		ft_free_list(&stack_a);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (!ft_is_sorted(stack_a))
		ft_sort(&stack_a);
	ft_free_list(&stack_a);
	return (0);
}

t_list	*ft_init_stack_a(char *argv[])
{
	t_list	*stack_a;
	char	**array;
	int		i;
	int		number;

	stack_a = NULL;
	i = 0;
	array = ft_split(argv[1], ' ');
	while (array[i])
	{
		number = ft_atoi(array[i]);
		ft_list_add_back(&stack_a, ft_list_new(number));
		i++;
	}
	ft_free_array(array);
	return (stack_a);
}

t_list	*ft_create_stack_a(int argc, char *argv[])
{
	t_list	*stack_a;
	int		i;
	int		number;

	i = 1;
	stack_a = NULL;
	if (argc == 2)
		stack_a = ft_init_stack_a(argv);
	else
	{
		while (i < argc)
		{
			number = ft_atoi(argv[i]);
			ft_list_add_back(&stack_a, ft_list_new(number));
			i++;
		}
	}
	return (stack_a);
}

int	ft_is_dup(t_list *current_a)
{
	t_list	*checked;

	while (current_a)
	{
		checked = current_a->next;
		while (checked)
		{
			if (current_a->number == checked->number)
				return (1);
			checked = checked->next;
		}
		current_a = current_a->next;
	}
	return (0);
}
