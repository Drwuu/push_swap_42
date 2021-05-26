/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:51:53 by drwuu             #+#    #+#             */
/*   Updated: 2021/05/26 04:05:06 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h> //remove

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (*alst)
	{
		last = ft_lstlast(*alst);
		new->previous = last;
		last->next = new;
	}
	else
		 *alst = new;
}
