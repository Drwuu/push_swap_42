/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 04:15:21 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/08 18:41:29 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"

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

void	random_nb_3(t_list **a_pile);
void	push_full(t_list **a_pile, t_list **b_pile, char *str);
void	algorithm(t_list **a_pile, t_list **b_pile, char *str);

void	write_pile_debug(t_list **pile);

#endif
