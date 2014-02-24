/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 15:56:00 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 16:07:08 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rtv1.h"

int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(1);
	(void)e;
	return (0);
}

void	ft_vector(t_env *e, int x, int y)
{
	e->view->vector->x = (WIDTH / 2) / tan(0.7854 / 2);
	e->view->vector->y = (-WIDTH / 2) + x;
	e->view->vector->z = HEIGHT / 2 - y;
}

int		ft_expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
