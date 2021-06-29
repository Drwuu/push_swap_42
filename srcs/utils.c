/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:43:26 by lwourms           #+#    #+#             */
/*   Updated: 2021/06/29 16:29:33 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_manager(t_datas *datas)
{
	if (datas->a_pile)
		ft_lstclear(&(datas->a_pile));
	if (datas->b_pile)
		ft_lstclear(&(datas->b_pile));
	if (datas->chunk)
		wrfree(datas->chunk);
	if (datas->str)
		wrfree(datas->str);
}

void	error_manager(t_datas *datas, const char *msg_error)
{
	free_manager(datas);
	ft_putstr_fd((char *)msg_error, 2);
	exit(0);
}

t_bool	already_exists(t_list *pile, int nb)
{
	while (pile)
	{
		if (nb == (int)pile->content)
			return (TRUE);
		pile = pile->next;
	}
	return (FALSE);
}

int	*set_array_nb(t_datas datas, t_list *pile, int size)
{
	int	*array_nb;
	int	i;

	array_nb = ft_calloc(sizeof(*array_nb), size);
	if (!array_nb)
		error_manager(&datas, "Malloc broke up\n");
	i = 0;
	while (i < size)
	{
		array_nb[i] = (int)pile->content;
		pile = pile->next;
		i++;
	}
	return (array_nb);
}

void	write_pile_debug(t_list *pile)
{
	char	*str;
	int		nb;

	while (pile)
	{
		nb = (int)pile->content;
		str = ft_itoa(nb);
		ft_putstr_fd(str, 1);
		wrfree(str);
		ft_putstr_fd("\n", 1);
		pile = pile->next;
	}
}
