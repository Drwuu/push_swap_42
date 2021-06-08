/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_nb_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:14:47 by lwourms           #+#    #+#             */
/*   Updated: 2021/06/08 19:15:42 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*find_lowest_nb_chain(t_list *pile)
{
	t_list	*lowest_nb_chain;

	lowest_nb_chain = pile;
	while (pile)
	{
		if (lowest_nb_chain->content > pile->content)
			lowest_nb_chain = pile;
		pile = pile->next;
	}
	return (lowest_nb_chain);
}

void	algorithm(t_list **a_pile, t_list **b_pile, char *str)
{
	t_list	*lowest_nb_chain;

	lowest_nb_chain = NULL;
	while (*a_pile)
	{
		lowest_nb_chain = find_lowest_nb_chain(*a_pile);
		pb(&lowest_nb_chain, b_pile, str);
		*a_pile = (*a_pile)->next;
	}
}

void	random_nb_3(t_list **a_pile)
{
	void	*nb1;
	void	*nb2;
	void	*nb3;

	nb1 = (*a_pile)->content;
	nb2 = (*a_pile)->next->content;
	nb3 = (*a_pile)->next->next->content;
	while ((int)nb1 > (int)nb2 || (int)nb2 > (int)nb3)
	{
		if (nb1 && nb2 && (int)nb1 > (int)nb2)
		{
			sa(a_pile);
			nb1 = (*a_pile)->content;
			nb2 = (*a_pile)->next->content;
		}
		if (nb2 && nb3 && (int)nb2 > (int)nb3)
		{
			rra(a_pile);
			nb1 = (*a_pile)->content;
			nb2 = (*a_pile)->next->content;
			nb3 = (*a_pile)->next->next->content;
		}
	}
}

void	random_nb_5(t_list **a_pile, t_list **b_pile, char *str)
{
	t_list	*temp;

	pb(a_pile, b_pile, str);
	pb(a_pile, b_pile, str);
	pb(a_pile, b_pile, str);
	temp = *a_pile;
	random_nb_3(a_pile);
	temp = *a_pile;
}

void	push_full(t_list **a_pile, t_list **b_pile, char *str)
{
	t_list	*temp;

	temp = *b_pile;
	while (temp)
	{
		pa(a_pile, b_pile, str);
		temp = temp->next;
	}
}
