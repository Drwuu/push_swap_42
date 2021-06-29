/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:14:47 by lwourms           #+#    #+#             */
/*   Updated: 2021/06/29 20:05:48 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_to_b_process_2(t_datas *datas, int mid_value, int *i)
{
	t_list	*last;
	int		best_path;

	last = ft_lstlast(datas->a_pile);
	best_path = find_best_path(datas->a_pile, mid_value, ft_is_smaller);
	if (best_path > 0)
	{
		while (best_path > 0)
		{
			ra(&(datas->a_pile));
			best_path--;
		}
	}
	else
	{
		while (best_path < 0)
		{
			rra(&last);
			last = ft_lstlast(datas->a_pile);
			best_path++;
		}
	}
	pb(&(datas->a_pile), &(datas->b_pile), datas->str);
	*i += 1;
}

static void	sort_to_b_process(t_datas *datas, int mid_index, int mid_value)
{
	t_list	*last;
	int		i;

	last = ft_lstlast(datas->a_pile);
	i = 0;
	while (i < mid_index)
	{
		if (is_pile_sorted(datas->a_pile, datas->chunk))
			while (i++ < mid_index)
				pb(&(datas->a_pile), &(datas->b_pile), datas->str);
		sort_to_b_process_2(datas, mid_value, &i);
	}
}

void	sort_to_b(t_datas *datas)
{
	int		mid_value;
	int		mid_index;
	int		size;

	while (datas->a_pile)
	{
		size = ft_lstsize(datas->a_pile);
		if (size < 6)
		{
			last_sort_pile_nb(datas, size);
			return ;
		}
		else if (size < 101)
			mid_index = size / 5;
		else if (size < 401)
			mid_index = size / 10;
		else
			mid_index = size / 15;
		datas->chunk = set_array_nb(*datas, datas->a_pile, size);
		ft_sort_array_ascending(&(datas->chunk), size);
		mid_value = datas->chunk[mid_index];
		if (is_pile_sorted(datas->a_pile, datas->chunk))
			return ;
		sort_to_b_process(datas, mid_index, mid_value);
	}
}

static void	sort_to_a_process(t_datas *datas, t_list *last, int *count)
{
	int		best_path;
	int		greater_nb;

	(void)count;
	greater_nb = find_greater_nb(ft_lstfirst(datas->b_pile));
	best_path = find_best_path(datas->b_pile, greater_nb, ft_is_equal);
	if (best_path > 0)
	{
		while (best_path > 0)
		{
			rb(&(datas->b_pile));
			best_path--;
		}
	}
	else
	{
		while (best_path < 0)
		{
			rrb(&last);
			last = ft_lstlast(datas->b_pile);
			best_path++;
		}
	}
	pa(&(datas->a_pile), &(datas->b_pile), datas->str);
}

void	sort_to_a(t_datas *datas)
{
	t_list	*last;
	int		count;

	count = 0;
	while (datas->b_pile)
	{
		last = ft_lstlast(datas->b_pile);
		sort_to_a_process(datas, last, &count);
	}
}
