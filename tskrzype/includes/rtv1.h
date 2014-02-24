/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 15:19:06 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 20:14:33 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define NAME "RTv1"
# define WIDTH 800
# define HEIGHT 800
# define BLUE_SPHERE 200
# define GREEN_SPHERE 155
# define RED_SPHERE 200
# define ANGLE 30

typedef struct	s_infos
{
	char		*data;
	int			b_p_p;
	int			size_line;
	int			endian;
}				t_infos;

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_view
{
	t_vector	*vector;
	t_vector	*tmp;
	float		x;
	float		y;
	float		z;
}				t_view;

typedef struct	s_color
{
	int		color1;
	int		color2;
	int		color3;
}				t_color;

typedef struct	s_sphere
{
	float		x;
	float		y;
	float		z;
	float		ray;
	t_color		*color;
}				t_sphere;

typedef struct	s_cylindre
{
	float		x;
	float		y;
	float		z;
	float		ray;
	t_color		*color;
}				t_cylindre;

typedef struct	s_plan
{
	float		x;
	float		y;
	float		z;
	t_color		*color;
}				t_plan;

typedef struct	s_inter
{
	float		x1;
	float		y1;
	float		z1;
	float		x2;
	float		y2;
	float		z2;
}				t_inter;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	t_infos		*infos;
	t_view		*view;
	t_sphere	*sphere;
	t_inter		*inter;
	t_vector	*light;
	t_plan		*plan;
	t_cylindre	*cylindre;
	float		coef_light;
	float		dist_p;
	float		dist_s;
}				t_env;

int		ft_get_index(t_env *e, int x, int y);
void	ft_put_pixel_sphere(t_env *e, int x, int y, t_color *color);
float	ft_normalize_sphere(float x, float y, float z, t_env *e);
float	ft_normalize_plan(float x, float y, float z, t_env *e);
float	ft_inter_plan(t_env *e);
int		ft_key_hook(int keycode, t_env *e);
void	ft_vector(t_env *e, int x, int y);
int		ft_expose_hook(t_env *e);
void	ft_inter_sphere(t_env *e, float result, float result2);
int		ft_check_inter_sphere(t_env *e);
void	ft_redirect(float dist_p, float x, float y, t_env *e);
void	ft_dist(float x, float y, t_env *e);
void	ft_init_cylindre(t_env *e);
int		ft_check_inter_cylindre(t_env *e);
float	ft_normalize_cylindre(float x, float y, float z, t_env *e);
void	ft_check_cylindre(t_env *e, float x, float y);
float	ft_calc_dist(t_env *e);

#endif /* !RTV1_h */
