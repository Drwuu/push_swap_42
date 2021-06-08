/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 02:04:23 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/08 19:26:23 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_error(void *to_free, void **to_free_2, t_list **lst_nullable, \
const char *msg_error)
{
	if (to_free)
		free(to_free);
	if (to_free_2)
		ft_free_dbl_array(to_free_2, 0);
	if (*lst_nullable || lst_nullable)
		ft_lstclear(lst_nullable);
	ft_putstr_fd((char *)msg_error, 2);
	exit(0);
}
