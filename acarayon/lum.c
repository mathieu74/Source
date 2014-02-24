/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:52:24 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 13:20:26 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "typedef.h"
#include "raytracing.h"
#include "libft.h"
#include "macros.h"

void				get_rgb(t_infos *s_infos, short mode)
{
	if (mode == -1)
	{
		s_infos->s_rgb.red = 0;
		s_infos->s_rgb.green = 0;
		s_infos->s_rgb.blue = 0;
	}
	if (mode == 0)
	{
		s_infos->s_rgb.red += (s_infos->color >> 16) % 0x100;
		s_infos->s_rgb.green += (s_infos->color >> 8) % 0x100;
		s_infos->s_rgb.blue += s_infos->color % 0x100;
	}
	if (mode == 1)
	{
		s_infos->color = 0x000000;
		s_infos->color +=
			(s_infos->s_rgb.red / s_infos->spots) * power(0x100, 2);
		s_infos->color += (s_infos->s_rgb.green / s_infos->spots) * 0x100;
		s_infos->color += s_infos->s_rgb.blue / s_infos->spots;
	}
}

static void		get_new_color(t_rt *s_rt, t_object *s_object, t_spot *s_spot,
								 t_infos *s_infos)
{
	short		i;

	i = 0;
	s_infos->color = 0x000000;
	s_infos->cos_alpha =
		((s_infos->s_norm.x * s_infos->s_lum.x
		+ s_infos->s_norm.y * s_infos->s_lum.y
		+ s_infos->s_norm.z * s_infos->s_lum.z)
		/ (sqrt(s_infos->s_norm.x * s_infos->s_norm.x
				+ s_infos->s_norm.y * s_infos->s_norm.y
				+ s_infos->s_norm.z * s_infos->s_norm.z)
		* sqrt(s_infos->s_lum.x * s_infos->s_lum.x
				+ s_infos->s_lum.y * s_infos->s_lum.y
				+ s_infos->s_lum.z * s_infos->s_lum.z)));
	if (s_infos->cos_alpha > 0.000001)
		while (i < s_rt->s_img.bpp / 8)
		{
			s_infos->color += (int)
				((((1.0 - s_object->gloss)
				* (float)((s_object->color >> 8 * i) % 0x100)
				+ (float)((s_spot->color >> 8 * i) % 0x100) * s_object->gloss))
				* s_infos->cos_alpha) * power(0x100, i);
			i++;
		}
}

void				lum(t_rt *s_rt, t_object *s_object, t_infos *s_infos)
{
	t_spot	*s_ptr_spot;

	s_infos->spots = 0;
	get_rgb(s_infos, -1);
	s_ptr_spot = s_rt->s_spot;
	while (s_ptr_spot)
	{
		s_infos->s_lum.x =
			s_ptr_spot->s_trans.x - s_infos->s_inter.x - s_object->s_trans.x;
		s_infos->s_lum.y =
			s_ptr_spot->s_trans.y - s_infos->s_inter.y - s_object->s_trans.y;
		s_infos->s_lum.z =
			s_ptr_spot->s_trans.z - s_infos->s_inter.z - s_object->s_trans.z;
		s_infos->color = s_object->color;
		get_new_color(s_rt, s_object, s_ptr_spot, s_infos);
		s_rt->mode = 1;
		shadow(s_rt, s_object, s_infos);
		s_rt->mode = 0;
		get_rgb(s_infos, 0);
		s_ptr_spot = s_ptr_spot->s_next;
		s_infos->spots++;
	}
	get_rgb(s_infos, 1);
}
