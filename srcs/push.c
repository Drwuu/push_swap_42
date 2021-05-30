/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:25:04 by drwuu             #+#    #+#             */
/*   Updated: 2021/05/29 15:21:31 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_list **a_pile, t_list **b_pile)
{
	if (*b_pile)
		ft_lstadd_front(a_pile, *b_pile);
}

void	pb(t_list **a_pile, t_list **b_pile)
{
	if (*a_pile)
	{
		*b_pile = ft_lstnew((*a_pile)->content, T_INT);
		ft_lstdelone(a_pile, free);
	}
}