/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:51:26 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/17 12:46:43 by mmole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "typedef.h"
#include "load_scene.h"
#include "raytracing.h"
#include "get_next_line.h"
#include "afunctions.h"
#include "libft.h"
#include "macros.h"

static void	get_object_func(fobject *object, int fd)
{
	char		*line;

	if ((line = get_next_line(fd, '\n')) == NULL)
		file_error();
	if (ft_strcmp(line, "sphere", '\0') == 0)
		*object = sphere;
//	if (ft_strcmp(line, "cylindre", '\0') == 0)
//		*object = cylindre;
	else
		file_error();
}

static void	fill_object_properties(t_object *s_object, int fd)
{
	char		*line;

	if ((line = get_next_line(fd, '\n')) == NULL)
		file_error();
	s_object->param = atoi_base(line, DEC);
	if ((line = get_next_line(fd, '\n')) == NULL)
		file_error();
	s_object->gloss = (float)atoi_base(line, DEC) / 1000.0;
	if ((line = get_next_line(fd, '\n')) == NULL)
		file_error();
	s_object->reflection = (float)atoi_base(line, DEC) / 1000.0;
	if ((line = get_next_line(fd, '\n')) == NULL)
		file_error();
}

static void	fill_object_color(t_rt *s_rt, t_object *s_object, int fd)
{
	char		*line;

	if ((line = get_next_line(fd, '\n')) == NULL)
		file_error();
	if (line[0] == 'x')
	{
		s_object->color = atoi_base(line + 1, HEX);
		s_object->s_img.img_ptr = NULL;
	}
	else if (line[0] == 't')
	{
		s_object->s_img.img_ptr =	amlx_xpm_file_to_image
			(s_rt->mlx_ptr, line + 1, TEX_SIZE, TEX_SIZE);
		s_object->s_img.data = amlx_get_data_addr
			(s_object->s_img.img_ptr, &s_object->s_img.bpp,
			&s_object->s_img.sizeline, &s_object->s_img.endian);
	}
	else
		file_error();
}

t_object	*get_objects(t_rt *s_rt, int fd)
{
	t_object	*s_begin_object;
	t_object	*s_ptr_object;
	char		*line;

	s_begin_object = NULL;
	while ((line = get_next_line(fd, '\n')) && line[0] == '-')
	{
		s_ptr_object = amalloc(sizeof(t_object));
		s_ptr_object->s_next = s_begin_object;
		fill_struct_s_coords(&s_ptr_object->s_trans, fd);
		fill_struct_s_coords(&s_ptr_object->s_rot, fd);
		fill_object_properties(s_ptr_object, fd);
		fill_object_color(s_rt, s_ptr_object, fd);
		get_object_func(&s_ptr_object->object, fd);
		s_begin_object = s_ptr_object;
	}
	return (s_begin_object);
}
