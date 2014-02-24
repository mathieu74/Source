/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amlx_get_data_addr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:56:49 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:38:44 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "libft.h"

char	*amlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line,
							int *endian)
{
	char		*data;

	if ((data = mlx_get_data_addr
		 (img_ptr, bits_per_pixel, size_line, endian)) == NULL)
	{
		ft_putstr("Mlx_get_data_addr error.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (data);
}
