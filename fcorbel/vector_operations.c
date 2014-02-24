/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 16:33:34 by fcorbel           #+#    #+#             */
/*   Updated: 2014/02/13 18:11:51 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <math.h>
#include "header_rtv1.h"

double			dot_product(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

void			cross_product(t_vec a, t_vec b, t_vec *tmp)
{
	tmp->x = (a.y * b.z) - (a.z * b.y);
	tmp->y = (a.z * b.x) - (a.x * b.z);
	tmp->z = (a.x * b.y) - (a.y * b.x);
}

t_vec			vec_vec(int operation, t_vec a, t_vec b)
{
	t_vec		tmp;

	if (operation == ADD)
	{
		tmp.x = a.x + b.x;
		tmp.y = a.y + b.y;
		tmp.z = a.z + b.z;
	}
	else if (operation == SUB)
	{
		tmp.x = a.x - b.x;
		tmp.y = a.y - b.y;
		tmp.z = a.z - b.z;
	}
	else if (operation == MUL)
	{
		tmp.x = a.x * b.x;
		tmp.y = a.y * b.y;
		tmp.z = a.z * b.z;
	}
	else if (operation == CROSS)
		cross_product(a, b, &tmp);
	return (tmp);
}

t_vec			vec_int(int operation, t_vec a, double b)
{
	t_vec		tmp;

	if (operation == ADD)
	{
		tmp.x = a.x + b;
		tmp.y = a.y + b;
		tmp.z = a.z + b;
	}
	else if (operation == SUB)
	{
		tmp.x = a.x - b;
		tmp.y = a.y - b;
		tmp.z = a.z - b;
	}
	else if (operation == MUL)
	{
		tmp.x = a.x * b;
		tmp.y = a.y * b;
		tmp.z = a.z * b;
	}
	else
		write(1, "Operating vector: Wrong operation", 33);
	return (tmp);
}
