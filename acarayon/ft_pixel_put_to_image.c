/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 12:18:30 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 12:18:31 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "typedef.h"

void	ft_pixel_put_to_image(t_rt *s_rt, int x, int y, int color)
{
	unsigned int	unsigned_color;
	short			i;

	i = 0;
	x = x * s_rt->s_img.bpp / 8;
	y = y * s_rt->s_img.sizeline;
	unsigned_color = mlx_get_color_value(s_rt->mlx_ptr, color);
	while (i < s_rt->s_img.bpp / 8)
	{
		s_rt->s_img.data[y + x + i] = (unsigned_color >> 8 * i) % 0x100;
		i++;
	}
}
