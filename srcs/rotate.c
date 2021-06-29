/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:25:04 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/25 11:09:40 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_list **a_pile)
{
	t_list	*temp;
	void	*save;

	temp = ft_lstlast(*a_pile);
	save = ft_lstlast(*a_pile)->content;
	while (temp)
	{
		if (temp->previous == NULL)
		{
			temp->content = save;
			ft_putstr_fd("rra\n", 1);
			return ;
		}
		temp->content = temp->previous->content;
		temp = temp->previous;
	}
}

void	rrb(t_list **b_pile)
{
	t_list	*temp;
	void	*save;

	temp = ft_lstlast(*b_pile);
	save = ft_lstlast(*b_pile)->content;
	while (temp)
	{
		if (temp->previous == NULL)
		{
			temp->content = save;
			ft_putstr_fd("rrb\n", 1);
			return ;
		}
		temp->content = temp->previous->content;
		temp = temp->previous;
	}
}

void	rrr(t_list **a_pile, t_list **b_pile)
{
	rra(a_pile);
	rrb(b_pile);
	ft_putstr_fd("rrr\n", 1);
}
