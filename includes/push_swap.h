/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 04:15:21 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/29 19:14:52 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include "../libft/includes/wr_malloc.h"

typedef struct s_datas
{
	t_list	*a_pile;
	t_list	*b_pile;
	char	*str;
	int		*chunk;
}	t_datas;

void	sa(t_list **a_pile);
void	sb(t_list **b_pile);
void	ss(t_list **a_pile, t_list **b_pile);

void	pa(t_list **a_pile, t_list **b_pile, char *str);
void	pb(t_list **a_pile, t_list **b_pile, char *str);

void	ra(t_list **a_pile);
void	rb(t_list **b_pile);
void	rr(t_list **a_pile, t_list **b_pile);

void	rra(t_list **a_pile);
void	rrb(t_list **b_pile);
void	rrr(t_list **a_pile, t_list **b_pile);

void	algorithm(t_datas *datas);

void	write_pile_debug(t_list *pile);
void	free_manager(t_datas *datas);
void	error_manager(t_datas *datas, const char *msg_error);
t_bool	already_exists(t_list *pile, int nb);

int		*set_array_nb(t_datas datas, t_list *pile, int size);
void	sort_to_a(t_datas *datas);
void	sort_to_b(t_datas *datas);
void	last_sort_pile_2_nb(t_list *pile);
void	last_sort_pile_3_nb(t_list *pile);
void	last_sort_pile_5_nb(t_datas *datas, int size);
void	last_sort_pile_nb(t_datas *datas, int size);

int		find_best_path(t_list *pile, int mid_value, t_bool f(int, int));
t_bool	is_greater_in_pile(t_list *start_pile, int nb);
t_bool	is_smaller_in_pile(t_list *start_pile, int nb);
int		find_greater_nb(t_list *first_pile);
int		find_smaller_nb(t_list *first_pile);
t_bool	is_pile_sorted(t_list *pile, int *array_sorted);
void	rra_push(t_datas *datas, int count);
void	rrb_push(t_datas *datas, int count);

#endif
