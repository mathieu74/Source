/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 17:06:12 by fcorbel           #+#    #+#             */
/*   Updated: 2014/02/16 17:17:03 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "header_rtv1.h"

double			compute_object(t_ray ray, t_object object)
{
	double		len;

	len = 0;
	if (object.type == SPHERE)
		len = sphere(ray, object);
	else if (object.type == PLAN)
		len = plan(ray, object);
	else if (object.type == CYLINDER)
		len = cylinder(ray, object);
	else if (object.type == CONE)
		len = cone(ray, object);
	return (len);
}

double			compute_intersect(t_env *e, t_ray ray)
{
	int			i;
	double		len;

	ray.t = MAX_DOUBLE;
	i = -1;
	while (++i < e->nb_obj)
	{
		if (e->obj[i].type != LIGHT)
		{
			len = compute_object(ray, e->obj[i]);
			if (len > 0 && len < ray.t)
			{
				ray.t = len;
				e->i_obj = i;
			}
		}
	}
	if (ray.t != MAX_DOUBLE)
		return (ray.t);
	return (0);
}

double			light_intersect(t_env *e, t_ray ray)
{
	int			i;
	double		len;

	ray.t = MAX_DOUBLE;
	i = -1;
	while (++i < e->nb_obj)
	{
		if (e->obj[i].type != LIGHT && i != e->i_obj && e->obj[i].type != PLAN)
		{
			len = compute_object(ray, e->obj[i]);
			if (len > 0 && len < ray.t)
				ray.t = len;
		}
	}
	if (ray.t != MAX_DOUBLE)
		return (ray.t);
	return (0);
}

double			compute_ray(int x, int y, t_env *e)
{
	t_vec		pixel;

	pixel = vec_int(MUL, e->right, (e->indent.x * (double)x));
	pixel = vec_vec(SUB, pixel, vec_int(MUL, e->up, (e->indent.y * (double)y)));
	pixel = vec_vec(ADD, vec_vec(SUB, e->view_upleft, e->ray.pos), pixel);
	e->ray.dir = norm(pixel);
	e->ray.t = compute_intersect(e, e->ray);
	if (e->ray.t)
	{
		if (compute_light(e))
			return (0);
		return (1);
	}
	return (0);
}
