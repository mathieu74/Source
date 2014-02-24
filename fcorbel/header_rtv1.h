/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_rtv1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 10:52:44 by fcorbel           #+#    #+#             */
/*   Updated: 2014/02/16 17:17:15 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HEADER_RTV1_H
# define HEADER_RTV1_H

# define NAME "RTV1"
# define ECHAP 65307
# define BUF_SIZE 4096
# define MAX_DOUBLE 1.7976931348623158e+308

# define WIN_X 1280.0
# define WIN_Y 960.0

# define VIEW 0.5, 0.35, 1.0
# define POS 150.0, 30.0, 200.0
# define LOOK_FIRST 10.0, -4.0, -20.0
# define UP_VEC 0.0, 1.0, 0.0

# define AMBIANT_COLOR 0.3

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_ray
{
	t_vec			pos;
	t_vec			dir;
	double			t;
}					t_ray;

typedef struct		s_dot
{
	double			x;
	double			y;
}					t_dot;

typedef struct		s_object
{
	int				type;
	t_vec			color;
	t_vec			coord;
	t_vec			vector;
	double			radius;
}					t_object;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*imlx;
	t_ray			ray;
	t_vec			view;
	t_vec			up;
	t_vec			right;
	t_vec			view_upleft;
	t_dot			indent;
	t_object		*obj;
	int				nb_obj;
	int				i_obj;
	t_vec			color;
}					t_env;

/* 
**RTV1
*/
void				init_e(t_env *e, char *file);
void				read_scene(t_env *e, char *file);
void				draw_img(t_env *e);
double				compute_ray(int x, int y, t_env *e);
double				compute_intersect(t_env *e, t_ray ray);
double				light_intersect(t_env *e, t_ray ray);
double				compute_light(t_env *e);
double				sphere(t_ray ray, t_object sp);
double				plan(t_ray ray, t_object pl);
double				cylinder(t_ray ray, t_object cy);
double				cone(t_ray ray, t_object co);

/*
** Tools
*/
# define ADD 1
# define SUB 2
# define MUL 3
# define CROSS 4
# define SPHERE 1
# define PLAN 2
# define CYLINDER 3
# define CONE 4
# define LIGHT 5

void				error(char *str);
int					ft_atoi(const char *str);
char				**ft_strsplit(char const *s, char c);

t_vec				init_vec(double x, double y, double z);
double				magnitude(t_vec tmp);
t_vec				norm(t_vec a);
double				dot_product(t_vec a, t_vec b);
t_vec				vec_vec(int operation, t_vec a, t_vec b);
t_vec				vec_int(int operation, t_vec a, double b);


#endif
