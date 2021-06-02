/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 02:04:23 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/02 17:10:52 by lwourms          ###   ########.fr       */
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
	if (lst_nullable)
		ft_lstclear(lst_nullable, free);
	ft_putstr_fd((char *)msg_error, 1);
	exit(0);
}
