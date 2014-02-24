/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:48:23 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 13:22:16 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "raytracing.h"
#include "afunctions.h"

t_infos	sphere
(t_rt *s_rt, t_object *s_object, t_coords *s_eye, t_coords *s_vec)
{
	t_infos		s_infos;
	t_eq		s_eq;

	s_eq.a = s_vec->x * s_vec->x + s_vec->y * s_vec->y + s_vec->z * s_vec->z;
	s_eq.b =
		2.0 * (s_eye->x * s_vec->x + s_eye->y * s_vec->y + s_eye->z * s_vec->z);
	s_eq.c = s_eye->x * s_eye->x + s_eye->y * s_eye->y
		+ s_eye->z * s_eye->z - s_object->param * s_object->param;
	equation_sec(&s_eq, &s_infos);
	if (s_infos.k1 > 0.000001 && s_rt->mode != 1)
	{
		s_infos.s_inter.x = s_infos.k1 * s_vec->x + s_eye->x;
		s_infos.s_inter.y = s_infos.k1 * s_vec->y + s_eye->y;
		s_infos.s_inter.z = s_infos.k1 * s_vec->z + s_eye->z;
		s_infos.s_norm = s_infos.s_inter;
		rotation(&s_object->s_rot, &s_infos.s_norm, 1);
		if (s_object->s_img.img_ptr)
		texture_color(s_object, &s_infos.s_inter, 250);
		lum(s_rt, s_object, &s_infos);
	}
	return (s_infos);
}
