/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:43:26 by lwourms           #+#    #+#             */
/*   Updated: 2021/06/29 19:06:26 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	last_sort_pile_4_nb(t_list *pile)
{
	if (pile->next && (int)pile->content > (int)pile->next->content)
		sa(&pile);
}

void	last_sort_pile_2_nb(t_list *pile)
{
	if (pile->next && (int)pile->content > (int)pile->next->content)
		sa(&pile);
}

void	last_sort_pile_nb(t_datas *datas, int size)
{
	while (datas->a_pile)
	{
		if (size < 4)
		{
			last_sort_pile_3_nb(datas->a_pile);
			return ;
		}
		else if (size < 6)
		{
			datas->chunk = set_array_nb(*datas, datas->a_pile, size);
			ft_sort_array_ascending(&(datas->chunk), size);
			if (is_pile_sorted(datas->a_pile, datas->chunk))
				return ;
			last_sort_pile_5_nb(datas, size);
			return ;
		}
		else if (is_smaller_in_pile(datas->a_pile, (int)datas->a_pile->content))
		{
			pb(&(datas->a_pile), &(datas->b_pile), datas->str);
			size--;
		}
		else
			ra(&(datas->a_pile));
	}
}
