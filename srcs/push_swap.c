/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:15:35 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/29 18:11:26 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_a_pile_process(t_datas *datas, int *i, long *nb)
{
	int	neg;

	neg = 1;
	if ((*datas).str[*i] == '-')
	{
		neg = -1;
		*i += 1;
	}
	if (!ft_isdigit((*datas).str[*i]))
		error_manager(datas, "Error\n");
	while (ft_isdigit((*datas).str[*i]))
	{
		*nb = *nb * 10 + (*datas).str[*i] - '0';
		*i += 1;
	}
	*nb *= neg;
	if (*nb > INT_MAX || *nb < INT_MIN || already_exists((*datas).a_pile, *nb))
		error_manager(datas, "Error\n");
	neg = 1;
}

void	init_a_pile(t_datas *datas)
{
	t_list	*new;
	long	nb;
	int		i;

	i = 0;
	nb = 0;
	while ((*datas).str[i])
	{
		init_a_pile_process(datas, &i, &nb);
		new = ft_lstnew((void *)nb, T_INT);
		if (!new)
			error_manager(datas, "Malloc broke up\n");
		ft_lstadd_back(&((*datas).a_pile), new);
		while (ft_iswhitespace((*datas).str[i]))
			i++;
		nb = 0;
	}
}

t_list	*push_swap(char *str)
{
	t_datas	datas;

	datas.str = str;
	datas.a_pile = NULL;
	datas.b_pile = NULL;
	datas.chunk = NULL;
	init_a_pile(&datas);
	algorithm(&datas);
	// dprintf(1, "push swap | printing pile a...\n");
	// write_pile_debug(datas.a_pile);
	// dprintf(1, "push swap | printing pile b...\n");
	write_pile_debug(datas.b_pile);
	free_manager(&datas);
	return (NULL);
}

int	main(int ac, char **av)
{
	char	*arg;
	int		i;

	i = 2;
	if (ac == 1)
		return (0);
	arg = ft_strdup(av[1]);
	if (!arg)
		ft_error(NULL, NULL, NULL, "Malloc broke up\n");
	if (ac == 2)
		push_swap(arg);
	else if (ac > 2)
	{
		while (i < ac)
		{
			arg = ft_strjoin_with_sep(arg, av[i++], ' ');
			if (!arg)
				ft_error(arg, NULL, NULL, "Malloc broke up\n");
		}
		push_swap(arg);
	}
	wrdestroy();
	return (0);
}
