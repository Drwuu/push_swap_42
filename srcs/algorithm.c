/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:14:47 by lwourms           #+#    #+#             */
/*   Updated: 2021/06/29 13:05:29 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm(t_datas *datas)
{
	int	lst_size;

	lst_size = ft_lstsize(datas->a_pile);
	if (lst_size == 1)
		return ;
	else if (lst_size == 2)
	{
		last_sort_pile_2_nb(datas->a_pile);
		return ;
	}
	sort_to_b(datas);
	sort_to_a(datas);
}
