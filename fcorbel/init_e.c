/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 11:09:03 by fcorbel           #+#    #+#             */
/*   Updated: 2014/02/16 12:44:50 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "header_rtv1.h"

void			init_upleft(t_env *e)
{
	t_vec		tmp;

	tmp = vec_int(MUL, e->ray.dir, e->view.z);
	tmp = vec_vec(ADD, tmp, vec_int(MUL, e->up, (e->view.y / 2.0)));
	tmp = vec_vec(SUB, tmp, vec_int(MUL, e->right, (e->view.x / 2.0)));
	tmp = vec_vec(ADD, e->ray.pos, tmp);
	e->view_upleft = tmp;
}

void			init_indent(t_env *e)
{
	t_dot		tmp;

	tmp.x = e->view.x / (double)WIN_X;
	tmp.y = e->view.y / (double)WIN_Y;
	e->indent = tmp;
}

void			init_ray_dir(t_env *e)
{
	t_vec		look_first;

	look_first = init_vec(LOOK_FIRST);
	e->ray.dir = vec_vec(SUB, look_first, e->ray.pos);
	e->ray.dir = norm(e->ray.dir);
}

void			init_e(t_env *e, char *file)
{
	e->ray.pos = init_vec(POS);
	init_ray_dir(e);
	e->view = init_vec(VIEW);
	e->up = init_vec(UP_VEC);
	e->right = norm(vec_vec(CROSS, e->up, e->ray.dir));
	e->up = norm(vec_vec(CROSS, e->ray.dir, e->right));
	init_upleft(e);
	init_indent(e);
	e->nb_obj = 0;
	e->i_obj = -1;
	read_scene(e, file);
}
