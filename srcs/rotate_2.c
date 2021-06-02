/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:25:04 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/02 20:13:59 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **a_pile)
{
	t_list	*temp;
	void	*save;

	temp = *a_pile;
	save = (*a_pile)->content;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->content = save;
			return ;
		}
		temp->content = temp->next->content;
		temp = temp->next;
	}
}

void	rb(t_list **b_pile)
{
	t_list	*temp;
	void	*save;

	temp = *b_pile;
	save = (*b_pile)->content;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->content = save;
			return ;
		}
		temp->content = temp->next->content;
		temp = temp->next;
	}
}

void	rr(t_list **a_pile, t_list **b_pile)
{
	ra(a_pile);
	rb(b_pile);
}
