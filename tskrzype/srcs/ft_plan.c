/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 15:38:35 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 20:11:50 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rtv1.h"

float	ft_inter_plan(t_env *e)
{
	float		result;
	float		x;
	float		y;
	float		z;
	t_vector	tmp2;
	float		dist;

	x = e->view->x - e->plan->x;
	y = e->view->y - e->plan->y;
	z = e->view->z - e->plan->z;
	result = -z / e->view->vector->z;
	if (result < 0)
		return (0);
	else
	{
		tmp2.x = e->view->vector->x * result + x;
		tmp2.y = e->view->vector->y * result + y;
		tmp2.z = e->view->vector->z * result + z;
		dist = sqrt(pow(tmp2.x - e->view->x, 2) + pow(tmp2.y - e->view->y, 2)
				+ pow(tmp2.z - e->view->z, 2));
		e->inter->x1 = tmp2.x;
		e->inter->y1 = tmp2.y;
		e->inter->z1 = tmp2.z;
	}
	return (dist);
}
