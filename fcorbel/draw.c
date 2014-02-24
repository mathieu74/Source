/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 11:10:10 by fcorbel           #+#    #+#             */
/*   Updated: 2014/02/16 17:12:48 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "header_rtv1.h"

static void		draw_pixel(int x, int y, t_env *e)
{
	char		*img;
	int			bpp;
	int			size_line;
	int			endian;
	int			index;

	img = mlx_get_data_addr(e->imlx, &bpp, &size_line, &endian);
	index = y * size_line + x * bpp / 8;
	if (index >= 0 && index < (WIN_Y * size_line + WIN_X * bpp / 8))
	{
		img[index + 0] = e->color.x * 255;
		img[index + 1] = e->color.y * 255;
		img[index + 2] = e->color.z * 255;
	}
}

void			draw_img(t_env *e)
{
	int			x;
	int			y;

	x = -1;
	while (++x <= WIN_X)
	{
		y = -1;
		while (++y <= WIN_Y)
		{
			if (compute_ray(x, y, e))
				draw_pixel(x, y, e);
		}
	}
}
