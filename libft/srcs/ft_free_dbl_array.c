/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dbl_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:22:19 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/25 02:26:30 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	**ft_free_dbl_array(void **datas, int size_nullable)
{
	int	i;

	i = 0;
	if (size_nullable)
	{
		while (i < size_nullable)
		{
			if (datas[i])
				free(datas[i]);
			i++;
		}
	}
	else
		while (datas[i])
			free(datas[i++]);
	free(datas);
	return (NULL);
}
