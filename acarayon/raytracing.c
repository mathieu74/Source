/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:59:29 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 13:03:40 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "typedef.h"
#include "raytracing.h"
#include "ft_pixel_put_to_image.h"
#include "libft.h"
#include "macros.h"

static void	k_iteration(t_rt *s_rt, t_infos *s_infos, t_infos *s_tmp_infos)
{
	if (s_tmp_infos->k1 > 0.000001 &&
		((s_rt->mode == 0 &&
		(s_tmp_infos->k1 < s_infos->k1 || s_infos->k1 == -1)) ||
		(s_rt->mode == 1 && s_tmp_infos->k1 < 1 &&
		(s_tmp_infos->k1 < s_infos->k1 || s_infos->k1 == -1))))
		*s_infos = *s_tmp_infos;
}

t_infos		get_object_infos(t_rt *s_rt, t_object *s_object, t_coords *s_eye,
							t_coords *s_vec)
{
	t_object	*s_ptr_object;
	t_infos		s_tmp_infos;
	t_infos		s_infos;
	t_coords	s_new_eye;
	t_coords	s_new_vec;

	s_infos.k1 = -1;
	s_infos.color = 0x000000;
	s_ptr_object = s_rt->s_object;
	while (s_ptr_object)
	{
		s_new_vec = *s_vec;
		rotation(&s_ptr_object->s_rot, &s_new_vec, 0);
		s_new_eye.x = s_eye->x - s_ptr_object->s_trans.x;
		s_new_eye.y = s_eye->y - s_ptr_object->s_trans.y;
		s_new_eye.z = s_eye->z - s_ptr_object->s_trans.z;
		s_tmp_infos = s_ptr_object->object
			(s_rt, s_ptr_object, &s_new_eye, &s_new_vec);
		if (s_object != s_ptr_object)
			k_iteration(s_rt, &s_infos, &s_tmp_infos);
		s_ptr_object = s_ptr_object->s_next;
	}
	return (s_infos);
}

void		shadow(t_rt *s_rt, t_object *s_object, t_infos *s_infos)
{
	t_coords	s_new_eye;
	t_coords	s_new_vec;
	int			color;
	short		i;

	i = 0;
	s_new_eye = s_infos->s_inter;
	s_new_eye.x += s_object->s_trans.x;
	s_new_eye.y += s_object->s_trans.y;
	s_new_eye.z += s_object->s_trans.z;
	s_new_vec = s_infos->s_lum;
	if (get_object_infos
		(s_rt, s_object, &s_new_eye, &s_new_vec).k1 != -1)
	{
		color = s_infos->color;
		s_infos->color = 0x000000;
		while (i < s_rt->s_img.bpp / 8)
		{
			s_infos->color += (int)((float)((color >> 8 * i) % 0x100) / 3.5) *
				power(0x100, i);
			i++;
		}
	}
}

void		raytracing(t_rt *s_rt)
{
	short		x;
	short		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			s_rt->s_vec.x = D;
			s_rt->s_vec.y = WIDTH / 2.0 - (float)x;
			s_rt->s_vec.z = HEIGHT / 2.0 - (float)y;
			rotation(&s_rt->s_rot, &s_rt->s_vec, 0);
			ft_pixel_put_to_image(s_rt, x++, y, get_object_infos
									(s_rt, NULL, &s_rt->s_eye,
									&s_rt->s_vec).color);
		}
		y++;
	}
}
