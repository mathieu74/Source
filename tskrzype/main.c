/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 15:19:55 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 20:10:21 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rtv1.h"

void	ft_init(t_env *e)
{
	e->view->x = 1;
	e->view->y = 0;
	e->view->z = 0;
	e->sphere->x = 40;
	e->sphere->y = 0;
	e->sphere->z = 0;
	e->sphere->ray = 5;
	e->light->x = 10;
	e->light->y = -40;
	e->light->z = 40;
	e->sphere->color->color1 = 200;
	e->sphere->color->color2 = 155;
	e->sphere->color->color3 = 200;
	e->plan->x = 0;
	e->plan->y = 0;
	e->plan->z = -20;
	e->plan->color->color1 = 0;
	e->plan->color->color2 = 200;
	e->plan->color->color3 = 200;
	ft_init_cylindre(e);
}

int		ft_check_inter_sphere(t_env *e)
{
	float	a;
	float	b;
	float	c;
	float	delta;
	float	result;

	a = pow(e->view->vector->x, 2) + pow(e->view->vector->y, 2)
		+ pow(e->view->vector->z, 2);
	b = 2 * ((e->view->vector->x * (e->view->x - e->sphere->x))
			+ (e->view->vector->y * (e->view->y - e->sphere->y))
			+ (e->view->vector->z * (e->view->z - e->sphere->z)));
	c = pow(e->view->x - e->sphere->x, 2) + pow(e->view->y - e->sphere->y, 2)
		+ pow(e->view->z - e->sphere->z, 2) - pow(e->sphere->ray, 2);
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

float	ft_calc_dist(t_env *e)
{
	float	dist1;
	float	dist2;

	dist1 = sqrt(pow(e->view->x - e->inter->x1, 2) +
			pow(e->view->y - e->inter->y1, 2) +
			pow(e->view->z - e->inter->z1, 2));
	dist2 = sqrt(pow(e->view->x - e->inter->x2, 2) +
			pow(e->view->y - e->inter->y2, 2) +
			pow(e->view->z - e->inter->z2, 2));
	if (dist1 < dist2)
		return (dist1);
	else
	{
		e->inter->x1 = e->inter->x2;
		e->inter->y1 = e->inter->y2;
		e->inter->z1 = e->inter->z2;
		return (dist2);
	}
}

void	ft_send_ray(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	ft_init(e);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_vector(e, x, y);
			e->dist_p = ft_inter_plan(e);
			if (ft_check_inter_sphere(e) == 1)
				e->dist_s = ft_calc_dist(e);
			if (e->dist_p != 0 && ft_check_inter_sphere(e) == 1)
				ft_dist(x, y, e);
			ft_redirect(e->dist_p, x, y, e);
			if (ft_check_inter_cylindre(e) == 1)
				ft_check_cylindre(e, x, y);
			x++;
		}
		y++;
	}
}

int		main(void)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	e->infos = (t_infos *)malloc(sizeof(t_infos));
	e->view = (t_view *)malloc(sizeof(t_view));
	e->sphere = (t_sphere *)malloc(sizeof(t_sphere));
	e->sphere->color = (t_color *)malloc(sizeof(t_color));
	e->plan = (t_plan *)malloc(sizeof(t_plan));
	e->plan->color = (t_color *)malloc(sizeof(t_color));
	e->inter = (t_inter *)malloc(sizeof(t_inter));
	e->view->vector = (t_vector *)malloc(sizeof(t_vector));
	e->view->tmp = (t_vector *)malloc(sizeof(t_vector));
	e->light = (t_vector *)malloc(sizeof(t_vector));
	e->cylindre = (t_cylindre *)malloc(sizeof(t_cylindre));
	e->cylindre->color = (t_color *)malloc(sizeof(t_color));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, NAME);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->infos->data = mlx_get_data_addr(e->img, &(e->infos->b_p_p),
			&(e->infos->size_line), &(e->infos->endian));
	ft_send_ray(e);
	mlx_key_hook(e->win, ft_key_hook, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
