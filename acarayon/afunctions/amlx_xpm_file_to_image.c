/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amlx_xpm_file_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:02:11 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:41:02 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft.h"

void	*amlx_xpm_file_to_image(void *mlx_ptr, char *filename, int width,
								int height)
{
	void		*img_ptr;

	img_ptr = mlx_xpm_file_to_image(mlx_ptr, filename, &width, &height);
	if (img_ptr == NULL)
	{
		ft_putstr("Mlx_xpm_file_to_image error.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (img_ptr);
}
