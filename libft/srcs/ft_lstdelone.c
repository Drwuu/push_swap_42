/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:51:53 by drwuu             #+#    #+#             */
/*   Updated: 2021/05/29 18:18:35 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdelone(t_list **lst, void (*del)(void*))
{
	t_list	*save;

	if (!lst)
		return ;
	if ((*lst)->type == T_STRING || (*lst)->type == T_DICT)
		del((*lst)->content);
	if ((*lst)->previous && (*lst)->next)
	{
		(*lst)->previous->next = (*lst)->next;
		(*lst)->next->previous = (*lst)->previous;
		free(*lst);
		dprintf(1, "free and link previous & next\n", (int)(*lst)->next);
	}
	else if ((*lst)->next)
	{
		save = *lst;
		*lst = (*lst)->next;
		dprintf(1, "free and link next %d\n", (int)(*lst)->next);
		free(save);
	}
	else if ((*lst)->previous)
	{
		save = *lst;
		*lst = (*lst)->previous;
		free(save);
		dprintf(1, "free and link previous\n");
	}
}
