/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 16:31:12 by fcorbel           #+#    #+#             */
/*   Updated: 2014/02/16 16:32:50 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "header_rtv1.h"

double			compute_len(double a, double b, double c)
{
	double		t1;
	double		t2;
	double		det;

	det = pow(b, 2) - (4 * a * c);
	t1 = (-b + sqrt(det)) / (2 * a);
	t2 = (-b - sqrt(det)) / (2 * a);
	if (det < 0)
		return (0);
	else if (det == 0)
		return (t1);
	else if (t1 > t2)
		return (t2);
	else if (t1 < t2)
		return (t1);
	return (0);
}

double			cone(t_ray ray, t_object co)
{
	double		a;
	double		b;
	double		c;
	t_vec		tmp;

	tmp = vec_vec(SUB, ray.pos, co.coord);
	co.radius *= 3.14159265359 / 180.0;
	a = pow(ray.dir.x, 2) + pow(ray.dir.y, 2) - pow(ray.dir.z, 2) *
		pow(tan(co.radius), 2);
	b = (2 * ray.dir.x * tmp.x) + (2 * ray.dir.y * tmp.y) -
		(2 * ray.dir.z * tmp.z) * pow(tan(co.radius), 2);
	c = pow(tmp.x, 2) + pow(tmp.y, 2) - pow(tmp.z, 2) * pow(tan(co.radius), 2);
	return (compute_len(a, b, c));
}

double			cylinder(t_ray ray, t_object cy)
{
	double		a;
	double		b;
	double		c;
	t_vec		tmp;

	tmp = vec_vec(SUB, ray.pos, cy.coord);
	a = pow(ray.dir.x, 2) + pow(ray.dir.y, 2);
	b = (2 * ray.dir.x * tmp.x) + (2 * ray.dir.y * tmp.y);
	c = pow(tmp.x, 2) + pow(tmp.y, 2) - pow(cy.radius, 2);
	return (compute_len(a, b, c));
}

double			plan(t_ray ray, t_object pl)
{
	double		t;
	t_vec		tmp;

	tmp = vec_vec(SUB, ray.pos, pl.coord);
	t = -(dot_product(pl.vector, tmp)) / dot_product(pl.vector, ray.dir);
	return (t);
}

double			sphere(t_ray ray, t_object sp)
{
	double		a;
	double		b;
	double		c;
	t_vec		tmp;

	tmp = vec_vec(SUB, ray.pos, sp.coord);
	a = pow(ray.dir.x, 2) + pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	b = ((ray.dir.x * tmp.x) + (ray.dir.y * tmp.y) + (ray.dir.z * tmp.z)) * 2;
	c = pow(tmp.x, 2) + pow(tmp.y, 2) + pow(tmp.z, 2) - pow(sp.radius, 2);
	return (compute_len(a, b, c));
}
