/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:25:04 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/08 17:52:06 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list **a_pile)
{
	void *temp;

	temp = NULL;
	if (*a_pile && (*a_pile)->next)
	{
		temp = (*a_pile)->content;
		(*a_pile)->content = (*a_pile)->next->content;
		(*a_pile)->next->content = temp;
	}
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **b_pile)
{
	void *temp;

	temp = NULL;
	if (*b_pile && (*b_pile)->next)
	{
		temp = (*b_pile)->content;
		(*b_pile)->content = (*b_pile)->next->content;
		(*b_pile)->next->content = temp;
	}
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **a_pile, t_list **b_pile)
{
	sa(a_pile);
	sb(b_pile);
	ft_putstr_fd("ss\n", 1);
}
