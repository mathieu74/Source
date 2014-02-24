/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rtv1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 10:48:14 by fcorbel           #+#    #+#             */
/*   Updated: 2014/02/16 17:07:04 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include "header_rtv1.h"

int				key_hook(int keycode)
{
	if (keycode == ECHAP)
		exit(0);
	return (0);
}

int				refresh(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->imlx, 0, 0);
	return (0);
}

int				main(int argc, char **argv)
{
	t_env		e;

	if (argc != 2)
		error("Error: Usage ./rtv1 scene.rt");
	init_e(&e, argv[1]);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, NAME);
	e.imlx = mlx_new_image(e.mlx, WIN_X, WIN_Y);
	mlx_string_put(e.mlx, e.win, 320, 220, 0x640000, "Please Wait...");
	mlx_key_hook(e.win, key_hook, &e);
	draw_img(&e);
	mlx_loop_hook(e.mlx, refresh, &e);
	mlx_loop(e.mlx);
	mlx_destroy_image(e.mlx, e.imlx);
	return (0);
}

void			error(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
	exit(0);
}
