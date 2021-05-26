/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:25:04 by drwuu             #+#    #+#             */
/*   Updated: 2021/05/26 15:57:39 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list **a_pile)
{
	void *temp;

	temp = 0;
	if (*a_pile && (*a_pile)->next)
	{
		temp = (*a_pile)->content;
		(*a_pile)->content = (*a_pile)->next->content;
		(*a_pile)->next->content = temp;
	}
}
