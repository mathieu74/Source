/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 15:20:43 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/15 19:41:19 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rtv1.h"

void	ft_put_pixel_sphere(t_env *e, int x, int y, t_color *color)
{
	int	i;

	i = ft_get_index(e, x, y);
	e->infos->data[i] = color->color1 * e->coef_light;
	e->infos->data[i + 1] = color->color2 * e->coef_light;
	e->infos->data[i + 2] = color->color3 * e->coef_light;
}
