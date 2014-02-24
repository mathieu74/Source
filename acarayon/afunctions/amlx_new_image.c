/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amlx_new_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:59:17 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:39:18 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft.h"

void	*amlx_new_image(void *mlx_ptr, int width, int height)
{
	void		*img_ptr;

	img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (img_ptr == NULL)
	{
		ft_putstr("Mlx_new_image error.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (img_ptr);
}
