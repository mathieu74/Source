/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 12:29:31 by fcorbel           #+#    #+#             */
/*   Updated: 2014/02/16 17:17:27 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "header_rtv1.h"

t_vec			compute_normal(t_env *e, t_ray ray)
{
	t_vec		tmp;
	int			type;

	type = e->obj[e->i_obj].type;
	if (type == SPHERE)
	{
		tmp = vec_vec(SUB, ray.pos, e->obj[e->i_obj].coord);
		tmp = vec_int(MUL, tmp, e->obj[e->i_obj].radius);
	}
	else if (type == PLAN)
		tmp = e->obj[e->i_obj].vector;
	else if (type == CYLINDER || type == CONE)
	{
		tmp.x = ray.pos.x - e->obj[e->i_obj].coord.x;
		tmp.y = ray.pos.y - e->obj[e->i_obj].coord.y;
		tmp.z = 0;
	}
	return (tmp);
}

double			get_light(t_env *e, t_ray ray, int i_light)
{
	t_vec		normal;
	double		attenuate;
	double		diffuse;

	normal = norm(compute_normal(e, ray));
	diffuse = dot_product(ray.dir, normal);
	if (diffuse > 0)
	{
		attenuate = 1.0 / (0.5 + 0.3 / ray.t + 0.7 / pow(ray.t, 2));
		e->color.x += (0.9 * diffuse * e->obj[i_light].color.x) * attenuate *
						e->obj[e->i_obj].color.x;
		e->color.y += (0.9 * diffuse * e->obj[i_light].color.y) * attenuate *
						e->obj[e->i_obj].color.y;
		e->color.z += (0.9 * diffuse * e->obj[i_light].color.x) * attenuate *
						e->obj[e->i_obj].color.z;
	}
	if (e->color.x > 1.0)
		e->color.x = 1.0;
	if (e->color.y > 1.0)
		e->color.y = 1.0;
	if (e->color.z > 1.0)
		e->color.z = 1.0;
	return (0);
}

double			compute_shadow(t_env *e, int i_light, t_vec pos)
{
	t_ray		ray_light;

	ray_light.pos = pos;
	ray_light.t = magnitude(vec_vec(SUB, e->obj[i_light].coord, pos));
	ray_light.dir = norm(vec_vec(SUB, e->obj[i_light].coord, pos));
	if (light_intersect(e, ray_light))
		return (1);
	get_light(e, ray_light, i_light);
	return (0);
}

double			compute_light(t_env *e)
{
	int			i;
	t_vec		pos;

	pos = vec_int(MUL, e->ray.dir, e->ray.t);
	pos = vec_vec(ADD, e->ray.pos, pos);
	i = -1;
	while (++i < e->nb_obj)
	{
		e->color = vec_int(MUL, e->obj[e->i_obj].color, AMBIANT_COLOR);
		if (e->obj[i].type == LIGHT)
		{
			if (compute_shadow(e, i, pos))
				return (0);
		}
	}
	return (0);
}
