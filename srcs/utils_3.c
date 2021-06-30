/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:43:26 by lwourms           #+#    #+#             */
/*   Updated: 2021/06/29 20:24:03 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_greater_nb(t_list *first_pile)
{
	int	greater_nb;

	greater_nb = (int)first_pile->content;
	while (first_pile)
	{
		if ((int)first_pile->content > greater_nb)
			greater_nb = (int)first_pile->content;
		first_pile = first_pile->next;
	}
	return (greater_nb);
}

int	find_smaller_nb(t_list *first_pile)
{
	int	smaller_nb;

	smaller_nb = (int)first_pile->content;
	while (first_pile)
	{
		if ((int)first_pile->content < smaller_nb)
			smaller_nb = (int)first_pile->content;
		first_pile = first_pile->next;
	}
	return (smaller_nb);
}

t_bool	is_pile_sorted(t_list *pile, int *array_sorted)
{
	int	i;

	i = 0;
	while (pile)
	{
		if ((int)pile->content != array_sorted[i++])
			return (FALSE);
		pile = pile->next;
	}
	return (TRUE);
}

void	rra_push(t_datas *datas, int count)
{
	while (count > 0)
	{
		rra(&(datas->a_pile));
		count--;
	}
	pb(&(datas->a_pile), &(datas->b_pile), datas->str);
}

void	rrb_push(t_datas *datas, int count)
{
	while (count > 0)
	{
		rrb(&(datas->b_pile));
		count--;
	}
	pa(&(datas->a_pile), &(datas->b_pile), datas->str);
}
