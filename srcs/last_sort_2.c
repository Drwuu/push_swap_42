/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:43:26 by lwourms           #+#    #+#             */
/*   Updated: 2021/06/29 19:07:54 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	last_sort_pile_5_nb_process(t_datas *datas, int size)
{
	t_list	*last;
	int		count;

	if (size == 5)
		count = 0;
	else
		count = 1;
	while (count < 2 && datas->a_pile)
	{
		last = ft_lstlast(datas->a_pile);
		if (is_smaller_in_pile(datas->a_pile, (int)datas->a_pile->content))
		{
			pb(&(datas->a_pile), &(datas->b_pile), datas->str);
			count++;
		}
		else if (is_smaller_in_pile(datas->a_pile, (int)last->content))
		{
			rra(&(datas->a_pile));
			pb(&(datas->a_pile), &(datas->b_pile), datas->str);
			count++;
		}
		else
			ra(&(datas->a_pile));
	}
}

void	last_sort_pile_5_nb(t_datas *datas, int size)
{
	last_sort_pile_5_nb_process(datas, size);
	last_sort_pile_3_nb(datas->a_pile);
	pa(&(datas->a_pile), &(datas->b_pile), datas->str);
	pa(&(datas->a_pile), &(datas->b_pile), datas->str);
}

void	last_sort_pile_3_nb(t_list *pile)
{
	void	*nb1;
	void	*nb2;
	void	*nb3;

	nb1 = pile->content;
	nb2 = pile->next->content;
	nb3 = pile->next->next->content;
	if ((int)nb1 > (int)nb2 && (int)nb2 < (int)nb3 && (int)nb3 > (int)nb1)
		sa(&pile);
	else if ((int)nb1 > (int)nb2 && (int)nb2 > (int)nb3 && (int)nb3 < (int)nb1)
	{
		sa(&pile);
		rra(&pile);
	}
	else if ((int)nb1 > (int)nb2 && (int)nb2 < (int)nb3 && (int)nb3 < (int)nb1)
		ra(&pile);
	else if ((int)nb1 < (int)nb2 && (int)nb2 > (int)nb3 && (int)nb3 > (int)nb1)
	{
		sa(&pile);
		ra(&pile);
	}
	else if ((int)nb1 < (int)nb2 && (int)nb2 > (int)nb3 && (int)nb3 < (int)nb1)
		rra(&pile);
}
