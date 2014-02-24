/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:48:59 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 13:21:59 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "typedef.h"
#include "macros.h"

static void	rotate_x(t_coords *s_vec, float rot)
{
	t_coords	s_old_vec;

	s_old_vec = *s_vec;
	s_vec->y
		= cosf(RAD(rot)) * s_old_vec.y
		- sinf(RAD(rot)) * s_old_vec.z;
	s_vec->z
		= sinf(RAD(rot)) * s_old_vec.y
		+ cosf(RAD(rot)) * s_old_vec.z;
}

static void	rotate_y(t_coords *s_vec, float rot)
{
	t_coords	s_old_vec;

	s_old_vec = *s_vec;
	s_vec->x
		= cosf(RAD(rot)) * s_old_vec.x
		+ sinf(RAD(rot)) * s_old_vec.z;
	s_vec->z
		= -sinf(RAD(rot)) * s_old_vec.x
		+ cosf(RAD(rot)) * s_old_vec.z;
}

static void	rotate_z(t_coords *s_vec, float rot)
{
	t_coords	s_old_vec;

	s_old_vec = *s_vec;
	s_vec->x
		= cosf(RAD(rot)) * s_old_vec.x
		- sinf(RAD(rot)) * s_old_vec.y;
	s_vec->y
		= sinf(RAD(rot)) * s_old_vec.x
		+ cosf(RAD(rot)) * s_old_vec.y;
}

void		rotation(t_coords *s_rot, t_coords *s_vec, short mode)
{
	if (mode == 0)
	{
		if (s_rot->x)
	rotate_x(s_vec, s_rot->x);
		if (s_rot->y)
			rotate_y(s_vec, s_rot->y);
		if (s_rot->z)
			rotate_z(s_vec, s_rot->z);
	}
	else if (mode == 1)
	{
		if (s_rot->x)
			rotate_x(s_vec, -s_rot->x);
		if (s_rot->y)
			rotate_y(s_vec, -s_rot->y);
		if (s_rot->z)
			rotate_z(s_vec, -s_rot->z);
	}
}
