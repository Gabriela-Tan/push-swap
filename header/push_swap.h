/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:46:49 by gabriela          #+#    #+#             */
/*   Updated: 2023/06/04 14:22:37 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	long			number;
	struct s_list	*next;
}	t_list;

//free memory
void	ft_free_list(t_list **stack);
void	ft_free_array(char **array);

//handle stack A
int		main(int argc, char *argv[]);
t_list	*ft_init_stack_a(char *argv[]);
t_list	*ft_create_stack_a(int argc, char *argv[]);
int		ft_is_dup(t_list *current_a);

//handle indexing
int		ft_index(t_list *stack, int number);
int		ft_index_stack_b(t_list *stack_b, int number);
int		ft_index_stack_a(t_list *stack_a, int number);

//list functions
void	ft_list_add_back(t_list **list, t_list *new);
t_list	*ft_list_new(int number);
t_list	*ft_list_last(t_list *list);
int		ft_list_size(t_list *list);

//operations
void	sa(t_list **head_a, int flag);
void	sb(t_list **head_b, int flag);
void	ss(t_list **head_a, t_list **head_b, int flag);
void	pa(t_list **head_a, t_list **head_b, int flag);
void	pb(t_list **head_a, t_list **head_b, int flag);
void	ra(t_list **head_a, int flag);
void	rb(t_list **head_b, int flag);
void	rr(t_list **head_a, t_list **head_b, int flag);
void	rra(t_list **head_a, int flag);
void	rrb(t_list **head_b, int flag);
void	rrr(t_list **head_a, t_list **head_b, int flag);

//sorting helpers
int		ft_is_sorted(t_list *current_a);
int		ft_find_min(t_list *current_a);
int		ft_find_max(t_list *current_a);

//rotating and pushing stacks
int		ft_check_moves_a(t_list *stack_a, t_list *stack_b);
int		moves_rarb_a(t_list *stack_a, t_list *stack_b, int number);
int		rarb_pa(t_list **stack_a, t_list **stack_b, int push);
int		moves_rrarrb_a(t_list *stack_a, t_list *stack_b, int number);
int		rrarrb_pa(t_list **stack_a, t_list **stack_b, int push);
int		moves_rarrb_a(t_list *stack_a, t_list *stack_b, int number);
int		rarrb_pa(t_list **stack_a, t_list **stack_b, int push);
int		moves_rrarb_a(t_list *stack_a, t_list *stack_b, int number);
int		rrarb_pa(t_list **stack_a, t_list **stack_b, int push);
int		ft_check_moves_b(t_list *stack_a, t_list *stack_b);
int		moves_rarb_b(t_list *stack_a, t_list *stack_b, int number);
int		rarb_pb(t_list **stack_a, t_list **stack_b, int push);
int		moves_rrarrb_b(t_list *stack_a, t_list *stack_b, int number);
int		rrarrb_pb(t_list **stack_a, t_list **stack_b, int push);
int		moves_rarrb_b(t_list *stack_a, t_list *stack_b, int number);
int		rarrb_pb(t_list **stack_a, t_list **stack_b, int push);
int		moves_rrarb_b(t_list *stack_a, t_list *stack_b, int number);
int		rrarb_pb(t_list **stack_a, t_list **stack_b, int push);

//stack sort
void	ft_sort_three(t_list **head_a);
void	ft_sort_more_b(t_list **stack_a, t_list **stack_b);
t_list	*ft_sort_b(t_list **stack_a);
t_list	**ft_sort_a(t_list **stack_a, t_list **stack_b);
void	ft_sort(t_list **stack_a);

#endif