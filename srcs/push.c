/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:25:04 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/08 17:51:41 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_list **a_pile, t_list **b_pile, char *str)
{
	t_list	*temp;

	temp = *a_pile;
	if (*b_pile)
	{
		if (temp)
		{
			temp = ft_lstnew((*b_pile)->content, T_INT);
			if (!temp)
			{
				ft_lstclear(b_pile);
				ft_error(str, NULL, a_pile, "Malloc broke up\n");
			}
			ft_lstadd_front(a_pile, temp);
		}
		else
		{
			*a_pile = ft_lstnew((*b_pile)->content, T_INT);
			if (!*a_pile)
				ft_error(str, NULL, b_pile, "Malloc broke up\n");
		}
		ft_lstdelone(b_pile);
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_list **a_pile, t_list **b_pile, char *str)
{
	t_list	*temp;

	temp = *b_pile;
	if (*a_pile)
	{
		if (temp)
		{
			temp = ft_lstnew((*a_pile)->content, T_INT);
			if (!temp)
			{
				ft_lstclear(a_pile);
				ft_error(str, NULL, b_pile, "Malloc broke up\n");
			}
			ft_lstadd_front(b_pile, temp);
		}
		else
		{
			*b_pile = ft_lstnew((*a_pile)->content, T_INT);
			if (!*b_pile)
				ft_error(str, NULL, a_pile, "Malloc broke up\n");
		}
		ft_lstdelone(a_pile);
		ft_putstr_fd("pb\n", 1);
	}
}
