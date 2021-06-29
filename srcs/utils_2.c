/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:43:26 by lwourms           #+#    #+#             */
/*   Updated: 2021/06/29 19:26:37 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	is_greater_in_pile(t_list *start_pile, int nb)
{
	while (start_pile)
	{
		if (nb < (int)start_pile->content)
			return (FALSE);
		start_pile = start_pile->next;
	}
	return (TRUE);
}

t_bool	is_smaller_in_pile(t_list *start_pile, int nb)
{
	while (start_pile)
	{
		if (nb > (int)start_pile->content)
			return (FALSE);
		start_pile = start_pile->next;
	}
	return (TRUE);
}

static int	count_asc_move(t_list *pile, int nb, t_bool f(int, int))
{
	int		count;

	count = 0;
	while (pile)
	{
		// if ((int)pile->content < nb)
		if (f((int)pile->content, nb))
			break ;
		pile = pile->next;
		count++;
	}
	return (count);
}

static int	count_dsc_move(t_list *pile, int nb, t_bool f(int, int))
{
	t_list	*last;
	int	count;

	count = 1;
	last = ft_lstlast(pile);
	while (last)
	{
		// dprintf(1, "count dsc move | last pile elem = %d\n", (int)last->content);
		if (f((int)last->content, nb))
		{
			// dprintf(1, "count dsc move | last content < mid value = %d\n", (int)last->content);
			// dprintf(1, "count dsc move | count = %d\n", count);
			break ;
		}
		last = last->previous;
		count++;
	}
	return (count);
}

int	find_best_path(t_list *pile, int mid_value, t_bool f(int, int))
{
	int		count_asc;
	int		count_dsc;

	count_asc = count_asc_move(pile, mid_value, f);
	count_dsc = count_dsc_move(pile, mid_value, f);
	if (count_asc < count_dsc)
		return (count_asc);
	else
		return (count_dsc * -1);
}
