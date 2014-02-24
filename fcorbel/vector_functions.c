/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 18:06:13 by fcorbel           #+#    #+#             */
/*   Updated: 2014/02/06 16:10:36 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <math.h>
#include "header_rtv1.h"

t_vec			init_vec(double x, double y, double z)
{
	t_vec		tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}

double			magnitude(t_vec tmp)
{
	return (sqrt(tmp.x * tmp.x + tmp.y * tmp.y + tmp.z * tmp.z));
}

t_vec			norm(t_vec a)
{
	t_vec		tmp;
	double		len;

	len = magnitude(a);
	tmp.x = a.x / len;
	tmp.y = a.y / len;
	tmp.z = a.z / len;
	return (tmp);
}
