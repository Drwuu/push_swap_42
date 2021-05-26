/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:15:35 by drwuu             #+#    #+#             */
/*   Updated: 2021/05/26 15:58:17 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	write_pile_debug(t_list **a_pile, t_list **b_pile)
{
	t_list	*temp;
	char	*str;
	int		nb;

	(void)b_pile;
	temp = *a_pile;
	while (temp)
	{
		nb = (int)temp->content;
		str = ft_itoa(nb);
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\n", 1);
		temp = temp->next;
	}
}

void	write_instructions(t_list **a_pile)
{
	(void)a_pile;
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
		new = ft_lstnew((void *)nb, T_INT);
		if (!new)
		{
			ft_lstclear(a_pile, free);
			ft_error(NULL, NULL, "Malloc broke up\n");
		}
		ft_lstadd_back(a_pile, new);
		while (ft_iswhitespace(str[i]))
			i++;
		nb = 0;
	}
}

t_list	*push_swap(char *str)
{
	t_list	*a_pile;
	t_list	*b_pile;

	a_pile = NULL;
	b_pile = NULL;
	init_pile(&a_pile, str);
	write_pile_debug(&a_pile, NULL);
	sa(&a_pile);
	ft_putstr_fd("sa\n", 1);
	write_pile_debug(&a_pile, NULL);
	return (NULL);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	else
		push_swap(av[1]);
}
