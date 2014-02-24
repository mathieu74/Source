/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 16:17:46 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 20:13:35 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rtv1.h"

void	ft_init_cylindre(t_env *e)
{
	e->cylindre->x = 40;
	e->cylindre->y = 10;
	e->cylindre->z = 0;
	e->cylindre->ray = 0.5;
	e->cylindre->color->color1 = 100;
	e->cylindre->color->color2 = 100;
	e->cylindre->color->color3 = 0;
}

void	ft_inter_sphere(t_env *e, float result, float result2)
{
	e->inter->x1 = e->view->x + e->view->vector->x * result;
	e->inter->y1 = e->view->y + e->view->vector->y * result;
	e->inter->z1 = e->view->z + e->view->vector->z * result;
	e->inter->x2 = e->view->x + e->view->vector->x * result2;
	e->inter->y2 = e->view->y + e->view->vector->y * result2;
	e->inter->z2 = e->view->z + e->view->vector->z * result2;
}

void	ft_dist(float x, float y, t_env *e)
{
	if (e->dist_p < e->dist_s)
	{
		ft_normalize_plan(e->inter->x1, e->inter->y1, e->inter->z1, e);
		ft_put_pixel_sphere(e, x, y, e->plan->color);
	}
	if (e->dist_s < e->dist_p)
	{
		ft_normalize_sphere(e->inter->x1, e->inter->y1, e->inter->z1, e);
		ft_put_pixel_sphere(e, x, y, e->sphere->color);
	}
}

void	ft_redirect(float dist_p, float x, float y, t_env *e)
{
	if (dist_p != 0 && ft_check_inter_sphere(e) == 0)
	{
		ft_normalize_plan(e->inter->x1, e->inter->y1, e->inter->z1, e);
		ft_put_pixel_sphere(e, x, y, e->plan->color);
	}
	if (dist_p == 0 && ft_check_inter_sphere(e) == 1)
	{
		ft_normalize_sphere(e->inter->x1, e->inter->y1, e->inter->z1, e);
		ft_put_pixel_sphere(e, x, y, e->sphere->color);
	}
}

int		ft_check_inter_cylindre(t_env *e)
{
	float	a;
	float	b;
	float	c;
	float	delta;
	float	result;

	a = pow(e->view->vector->x, 2) + pow(e->view->vector->y, 2);
	b = 2 * (e->view->vector->x * (e->view->x - e->cylindre->x) +
			e->view->vector->y * (e->view->y - e->cylindre->y));
	c = pow((e->view->x - e->cylindre->x), 2) + pow((e->view->y -
				e->cylindre->y), 2) - pow(e->cylindre->ray, 2);
	delta = pow(b, 2) - 4 * a * c;
	c = (-b - sqrt(delta)) / (2 * a);
	result = (-b + sqrt(delta)) / (2 * a);
	if (delta < 0)
		return (0);
	if (delta > 0)
	{
		ft_inter_sphere(e, c, result);
		return (1);
	}
	return (0);
}
