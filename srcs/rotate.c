/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:25:04 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/02 20:13:44 by lwourms          ###   ########.fr       */
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
}
