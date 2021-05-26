/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:25:04 by drwuu             #+#    #+#             */
/*   Updated: 2021/05/26 02:39:34 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_list **a_pile)
{
	int	temp;

	temp = 0;
	if (*a_pile && (*a_pile)->next)
	{
		temp = (*a_pile)->content;
		(*a_pile)->content = (*a_pile)->next->content;
		(*a_pile)->next->content = temp;
	}
	//*a_pile = ft_lstfirst(*a_pile);
}
