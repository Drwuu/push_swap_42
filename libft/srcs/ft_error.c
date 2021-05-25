/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 02:04:23 by drwuu             #+#    #+#             */
/*   Updated: 2021/05/25 02:43:23 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_error(void *to_free, void **to_free_2, const char *msg_error)
{
	if (to_free)
		free(to_free);
	if (to_free_2)
		ft_free_dbl_array(to_free_2, 0);
	ft_putstr_fd(msg_error, 1);
	exit(0);
}
