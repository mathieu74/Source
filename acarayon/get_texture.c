/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:51:59 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 21:04:08 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "macros.h"
#include "libft.h"

void	texture_color(t_object *s_object, t_coords *s_inter, int dezoom)
{
	int		x;
	int		y;
	short	i;

	i = 0;
	s_object->color = 0x000000;
	if ((x = (int)(s_inter->y / s_inter->x * dezoom) % TEX_SIZE) < 0)
		x += TEX_SIZE;
	if ((y = (int)(s_inter->z / s_inter->x * dezoom) % TEX_SIZE) < 0)
		y += TEX_SIZE;
	x *= s_object->s_img.bpp / 8;
	y *= s_object->s_img.sizeline;
	while (i < s_object->s_img.bpp / 8)
	{
		s_object->color +=
			(unsigned char)s_object->s_img.data[y + x + i] * power(0x100, i);
		i++;
	}
}
