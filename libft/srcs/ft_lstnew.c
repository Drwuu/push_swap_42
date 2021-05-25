/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:51:53 by drwuu             #+#    #+#             */
/*   Updated: 2021/05/16 19:08:04 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content, t_type type)
{
	t_list	*new_elem;

	if (!content)
		return (NULL);
	new_elem = malloc(sizeof(*new_elem));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->type = type;
	new_elem->next = NULL;
	new_elem->previous = NULL;
	return (new_elem);
}
