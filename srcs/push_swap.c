/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:15:35 by drwuu             #+#    #+#             */
/*   Updated: 2021/05/25 05:10:18 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	write_pile_debug(t_list **a_pile, t_list **b_pile)
{
	int	nb;

	nb = 0;
	//*a_pile = ft_lstfirst(*a_pile);
	while (*a_pile)
	{
		nb = (*a_pile)->content;
		ft_putstr_fd(ft_itoa(nb), 1);
		ft_putstr_fd("\n", 1);
		*a_pile = (*a_pile)->next;
	}
}

void	write_instructions(t_list **a_pile)
{

}

void	init_pile(t_list **a_pile, char *str)
{
	t_list	*new;
	long	nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i]) 
	{
		if (!ft_isdigit(str[i]))
			ft_error(NULL, NULL, "Error\n");
		while (ft_isdigit(str[i]))
			nb = nb * 10 + str[i++] - '0';
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error(NULL, NULL, "Error\n");
		new = ft_lstnew(nb, T_INT);
		if (!new)
		{
			ft_lstclear(a_pile, free);
			ft_error(NULL, NULL, "Malloc broke up\n");
		}
		ft_lstadd_back(a_pile, new);
		nb = 0;
		while (ft_iswhitespace(str[i]))
			i++;
	}
	ft_putstr_fd(ft_itoa((*a_pile)->content), 1);
	ft_putstr_fd("bouh\n", 1);
	*a_pile = ft_lstfirst(*a_pile);
	ft_putstr_fd(ft_itoa((*a_pile)->content), 1);
	ft_putstr_fd("bouh ouh\n", 1);
}

t_list	*push_swap(char *str)
{
	t_list	*a_pile;
	t_list	*b_pile;

	a_pile = ft_lstnew(0, T_INT);
	// if (!a_pile)
	// {
	// 	ft_putstr_fd("coucou\n", 1);
	// 	ft_error(NULL, NULL, "Malloc broke up\n");
	// }
	init_pile(&a_pile, str);
	write_pile_debug(&a_pile, NULL);
	swap_a(&a_pile);
	write_pile_debug(&a_pile, NULL);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	else
		push_swap(av[1]);
}
