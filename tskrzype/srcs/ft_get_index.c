/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 15:20:22 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/10 15:20:25 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rtv1.h"

int	ft_get_index(t_env *e, int x, int y)
{
	int	index;
	int	x_oct;
	int	y_oct;

	x_oct = x * (e->infos->b_p_p / 8);
	y_oct = y * e->infos->size_line;
	index = x_oct + y_oct;
	return (index);
}
