/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:32:41 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 13:49:27 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct	s_eq	t_eq;
typedef struct	s_coords	t_coords;
typedef struct	s_rgb	t_rgb;
typedef struct	s_img	t_img;
typedef struct	s_object	t_object;
typedef struct	s_infos	t_infos;
typedef struct	s_spot	t_spot;
typedef struct	s_rt	t_rt;
typedef t_infos (*fobject) (t_rt *, t_object *, t_coords *, t_coords *);

struct			s_eq
{
	float		a;
	float		b;
	float		c;
	float		delta;
	float		k1;
	float		k2;
};

struct			s_coords
{
	float		x;
	float		y;
	float		z;
};

struct			s_rgb
{
	int			red;
	int			green;
	int			blue;
};

struct			s_img
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
};

struct			s_object
{
	t_coords	s_trans;
	t_coords	s_rot;
	t_object	*s_next;
	t_img		s_img;
	float		param;
	float		gloss;
	float		reflection;
	float		transparency;
	int			color;
	fobject		object;
};

struct			s_infos
{
	t_coords	s_inter;
	t_coords	s_norm;
	t_coords	s_lum;
	t_rgb		s_rgb;
	float		k1;
	float		k2;
	float		cos_alpha;
	int			color;
	int			spots;
};

struct			s_spot
{
	t_coords	s_trans;
	t_spot		*s_next;
	int			color;
};

struct			s_rt
{
	t_object	*s_object;
	t_spot		*s_spot;
	t_coords	s_eye;
	t_coords	s_trans;
	t_coords	s_rot;
	t_coords	s_vec;
	t_img		s_img;
	void		*mlx_ptr;
	void		*win_ptr;
	short		mode;
};


#endif /* !TYPEDEF_H */
