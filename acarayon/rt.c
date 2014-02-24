/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:30:35 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 13:18:19 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "typedef.h"
#include "load_scene.h"
#include "raytracing.h"
#include "afunctions.h"
#include "libft.h"
#include "macros.h"

static int	expose_hook(t_rt *s_rt)
{
	mlx_put_image_to_window
		(s_rt->mlx_ptr, s_rt->win_ptr, s_rt->s_img.img_ptr, 0, 0);
	return (0);
}

static int	key_hook(int keycode, t_rt *s_rt)
{
	t_object	*s_prev_object;
	t_spot		*s_prev_spot;

	if (keycode == ESC)
	{
		mlx_destroy_window(s_rt->mlx_ptr, s_rt->win_ptr);
		mlx_destroy_image(s_rt->mlx_ptr, s_rt->s_img.img_ptr);
		while (s_rt->s_object)
		{
			s_prev_object = s_rt->s_object;
			if (s_rt->s_object->s_img.img_ptr)
				mlx_destroy_image(s_rt->mlx_ptr, s_rt->s_object->s_img.img_ptr);
			s_rt->s_object = s_rt->s_object->s_next;
			free(s_prev_object);
		}
		while (s_rt->s_spot)
		{
			s_prev_spot = s_rt->s_spot;
			s_rt->s_spot = s_rt->s_spot->s_next;
			free(s_prev_spot);
		}
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static void	init_mlx(t_rt *s_rt)
{
	s_rt->mlx_ptr = amlx_init();
	s_rt->s_img.img_ptr = amlx_new_image(s_rt->mlx_ptr, WIDTH, HEIGHT);
	s_rt->s_img.data = amlx_get_data_addr
		(s_rt->s_img.img_ptr, &s_rt->s_img.bpp,
		&s_rt->s_img.sizeline, &s_rt->s_img.endian);
}

static void	launch_mlx(t_rt *s_rt)
{
	s_rt->win_ptr = amlx_new_window(s_rt->mlx_ptr, WIDTH, HEIGHT, WIN_NAME);
	mlx_expose_hook(s_rt->win_ptr, expose_hook, s_rt);
	mlx_key_hook(s_rt->win_ptr, key_hook, s_rt);
}

int			main(int argc, char **argv)
{
	t_rt		s_rt;

	if (argc == 3)
	{
		s_rt.s_eye.x = -3000;
		s_rt.s_eye.y = 0;
		s_rt.s_eye.z = 0;
		s_rt.s_rot.x = 0;
		s_rt.s_rot.y = 0;
		s_rt.s_rot.z = 0;
		s_rt.mode = 0;
		init_mlx(&s_rt);
		load_scene(&s_rt, argv);
		raytracing(&s_rt);
		launch_mlx(&s_rt);
		mlx_loop(s_rt.mlx_ptr);
	}
	else
		ft_putstr("Usage : ./rtv1 misc/objects.rt misc/spots.rt\n", 2);
	return (EXIT_SUCCESS);
}
