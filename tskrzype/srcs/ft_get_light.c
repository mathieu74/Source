/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 12:28:37 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 19:47:06 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rtv1.h"

float	ft_normalize_sphere(float x, float y, float z, t_env *e)
{
	t_vector	tmp1;
	t_vector	tmp2;
	t_vector	tmp1f;
	t_vector	tmp2f;
	float	vector1;

	tmp1.x = x - e->sphere->x;
	tmp1.y = y - e->sphere->y;
	tmp1.z = z - e->sphere->z;
	vector1 = sqrt(pow(tmp1.x, 2) + pow(tmp1.y, 2) + pow(tmp1.z, 2));
	tmp1f.x = tmp1.x / vector1;
	tmp1f.y = tmp1.y / vector1;
	tmp1f.z = tmp1.z / vector1;
	tmp2.x = e->light->x - x;
	tmp2.y = e->light->y - y;
	tmp2.z = e->light->z - z;
	vector1 = sqrt(pow(tmp2.x, 2) + pow(tmp2.y, 2) + pow(tmp2.z, 2));
	tmp2f.x = tmp2.x / vector1;
	tmp2f.y = tmp2.y / vector1;
	tmp2f.z = tmp2.z / vector1;
	e->coef_light = tmp1f.x * tmp2f.x + tmp1f.y * tmp2f.y + tmp1f.z * tmp2f.z;
	if (e->coef_light < 0)
		e->coef_light = 0.1;
	return (e->coef_light);
}

float	ft_normalize_plan(float x, float y, float z, t_env *e)
{
	t_vector	tmp2;
	t_vector	tmp1f;
	t_vector	tmp2f;
	float		vector1;

	tmp1f.x = 0;
	tmp1f.y = 0;
	tmp1f.z = 1;
	tmp2.x = e->light->x - x;
	tmp2.y = e->light->y - y;
	tmp2.z = e->light->z - z;
	vector1 = sqrt(pow(tmp2.x, 2) + pow(tmp2.y, 2) + pow(tmp2.z, 2));
	tmp2f.x = tmp2.x / vector1;
	tmp2f.y = tmp2.y / vector1;
	tmp2f.z = tmp2.z / vector1;
	e->coef_light = tmp1f.x * tmp2f.x + tmp1f.y * tmp2f.y + tmp1f.z * tmp2f.z;
	if (e->coef_light < 0)
		e->coef_light = 0.1;
	return (e->coef_light);
}
