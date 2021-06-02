/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:51:53 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/02 19:33:02 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	process(t_list **lst, t_list *save)
{
	if ((*lst)->previous && (*lst)->next)
	{
		(*lst)->previous->next = (*lst)->next;
		(*lst)->next->previous = (*lst)->previous;
	}
	else if ((*lst)->previous)
	{
		save = *lst;
		*lst = (*lst)->previous;
		(*lst)->next = NULL;
	}
	else if ((*lst)->next)
	{
		save = *lst;
		*lst = (*lst)->next;
		(*lst)->previous = NULL;
	}
	if (save)
		free(save);
	else
		free(*lst);
}

void	ft_lstdelone(t_list **lst, void (*del)(void*))
{
	t_list	*save;

	if (!lst)
		return ;
	if ((*lst)->type == T_STRING || (*lst)->type == T_DICT)
		del((*lst)->content);
	save = NULL;
	process(lst, save);
	// if ((*lst)->type == T_STRING || (*lst)->type == T_DICT)
	// 	del((*lst)->content);
	// if ((*lst)->previous && (*lst)->next)
	// {
	// 	(*lst)->previous->next = (*lst)->next;
	// 	(*lst)->next->previous = (*lst)->previous;
	// }
	// else if ((*lst)->previous)
	// {
	// 	save = *lst;
	// 	*lst = (*lst)->previous;
	// 	(*lst)->next = NULL;
	// }
	// else if ((*lst)->next)
	// {
	// 	save = *lst;
	// 	*lst = (*lst)->next;
	// 	(*lst)->previous = NULL;
	// }
	// if (save)
	// 	free(save);
	// else
	// 	free(*lst);
}
