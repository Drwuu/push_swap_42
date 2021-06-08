/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:15:35 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/08 19:32:05 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	write_pile_debug(t_list **pile)
{
	t_list	*temp;
	char	*str;
	int		nb;

	temp = *pile;
	while (temp)
	{
		nb = (int)temp->content;
		str = ft_itoa(nb);
		ft_putstr_fd(str, 1);
		free(str);
		ft_putstr_fd("\n", 1);
		temp = temp->next;
	}
}

static t_bool	is_already_present(t_list *pile, int nb)
{
	while (pile)
	{
		if (nb == (int)pile->content)
			return (TRUE);
		pile = pile->next;
	}
	return (FALSE);
}

void	init_a_pile(t_list **a_pile, char *str)
{
	t_list	*new;
	long	nb;
	int		neg;
	int		i;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error(str, NULL, a_pile, "Error\n");
		if (str[i] == '-')
			neg = -1;
		while (ft_isdigit(str[i]))
		{
			nb = nb * 10 + str[i++] - '0';
			nb *= neg;
		}
		if (nb > INT_MAX || nb < INT_MIN || is_already_present(*a_pile, nb))
			ft_error(str, NULL, a_pile, "Error\n");
		new = ft_lstnew((void *)nb, T_INT);
		if (!new)
			ft_error(str, NULL, a_pile, "Malloc broke up\n");
		ft_lstadd_back(a_pile, new);
		while (ft_iswhitespace(str[i]))
			i++;
		nb = 0;
		neg = 1;
	}
}

t_list	*push_swap(char *str)
{
	t_list	*a_pile;
	t_list	*b_pile;

	a_pile = NULL;
	b_pile = NULL;
	init_a_pile(&a_pile, str);

	algorithm(&a_pile, &b_pile, str);
	ft_putstr_fd("\n", 1);

	ft_putstr_fd("write pile a\n", 1);
	write_pile_debug(&a_pile);
	ft_putstr_fd("\n", 1);

	ft_putstr_fd("write pile b\n", 1);
	write_pile_debug(&b_pile);
	ft_putstr_fd("\n", 1);

	push_full(&a_pile, &b_pile, str);
	ft_putstr_fd("write pile a\n", 1);
	write_pile_debug(&a_pile);
	ft_putstr_fd("\n", 1);

	// ft_putstr_fd("sa\n", 1);
	// sa(&a_pile);
	// ft_putstr_fd("write pile a\n", 1);
	// write_pile_debug(&a_pile);
	// ft_putstr_fd("\n", 1);


	// ft_putstr_fd("pb\n", 1);
	// pb(&a_pile, &b_pile, str);
	// ft_putstr_fd("write pile a\n", 1);
	// write_pile_debug(&a_pile);
	// ft_putstr_fd("write pile b\n", 1);
	// write_pile_debug(&b_pile);
	// ft_putstr_fd("\n", 1);


	// ft_putstr_fd("pa\n", 1);
	// ft_putstr_fd("pa\n", 1);
	// pa(&a_pile, &b_pile, str);
	// pa(&a_pile, &b_pile, str);
	// ft_putstr_fd("write pile a\n", 1);
	// write_pile_debug(&a_pile);
	// ft_putstr_fd("write pile b\n", 1);
	// write_pile_debug(&b_pile);
	// ft_putstr_fd("\n", 1);


	// ft_putstr_fd("pb\n", 1);
	// ft_putstr_fd("pb\n", 1);
	// pb(&a_pile, &b_pile, str);
	// pb(&a_pile, &b_pile, str);
	// ft_putstr_fd("write pile a\n", 1);
	// write_pile_debug(&a_pile);
	// ft_putstr_fd("write pile b\n", 1);
	// write_pile_debug(&b_pile);
	// ft_putstr_fd("\n", 1);


	// ft_putstr_fd("sb\n", 1);
	// sb(&b_pile);
	// ft_putstr_fd("write pile b\n", 1);
	// write_pile_debug(&b_pile);
	// ft_putstr_fd("\n", 1);


	// ft_putstr_fd("ss\n", 1);
	// ss(&a_pile, &b_pile);
	// ft_putstr_fd("write pile a\n", 1);
	// write_pile_debug(&a_pile);
	// ft_putstr_fd("\n", 1);
	// ft_putstr_fd("write pile b\n", 1);
	// write_pile_debug(&b_pile);
	// ft_putstr_fd("\n", 1);


	// ft_putstr_fd("ra\n", 1);
	// ra(&a_pile);
	// ft_putstr_fd("write pile a\n", 1);
	// write_pile_debug(&a_pile);
	// ft_putstr_fd("\n", 1);


	// ft_putstr_fd("rra\n", 1);
	// rra(&a_pile);
	// ft_putstr_fd("write pile a\n", 1);
	// write_pile_debug(&a_pile);
	// ft_putstr_fd("\n", 1);


	// ft_putstr_fd("rra\n", 1);
	// rra(&a_pile);
	// ft_putstr_fd("write pile a\n", 1);
	// write_pile_debug(&a_pile);
	// ft_putstr_fd("\n", 1);


	// ft_putstr_fd("rrb\n", 1);
	// rrb(&b_pile);
	// ft_putstr_fd("write pile b\n", 1);
	// write_pile_debug(&b_pile);
	// ft_putstr_fd("\n", 1);


	// ft_putstr_fd("rrb\n", 1);
	// rrb(&b_pile);
	// ft_putstr_fd("write pile b\n", 1);
	// write_pile_debug(&b_pile);
	// ft_putstr_fd("\n", 1);


	// ft_putstr_fd("rb\n", 1);
	// rb(&b_pile);
	// ft_putstr_fd("write pile b\n", 1);
	// write_pile_debug(&b_pile);
	// ft_putstr_fd("\n", 1);


	// ft_putstr_fd("rrr\n", 1);
	// rrr(&a_pile, &b_pile);
	// ft_putstr_fd("write pile a\n", 1);
	// write_pile_debug(&a_pile);
	// ft_putstr_fd("\n", 1);
	// ft_putstr_fd("write pile b\n", 1);
	// write_pile_debug(&b_pile);
	// ft_putstr_fd("\n", 1);


	ft_lstclear(&a_pile);
	ft_lstclear(&b_pile);
	return (NULL);
}

int	main(int ac, char **av)
{
	char	*arg;
	int		i;

	i = 2;
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
	free(arg);
	return (0);
}
