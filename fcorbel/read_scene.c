/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 17:12:57 by fcorbel           #+#    #+#             */
/*   Updated: 2014/02/16 17:07:27 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "header_rtv1.h"

void			free_split(char **split)
{
	int			i;

	i = -1;
	while (split[i])
		free(split[i]);
	free(split);
}

t_vec			get_hex_color(char *line)
{
	int				i;
	int				color_int;
	t_vec			color;

	i = 1;
	color = init_vec(0, 0, 0);
	color_int = 0;
	while (line[++i])
	{
		if (line[i] >= '0' && line[i] <= '9')
			color_int = color_int * 16 + (line[i] - '0');
		else if (line[i] >= 'A' && line[i] <= 'F')
			color_int = color_int * 16 + (line[i] - 'A' + 10);
		else
			error("Error: Wrong color input.");
	}
	color.x = (double)(color_int % 256) / 255.0;
	color.y = (double)(color_int / 256 % 256) / 255.0;
	color.z = (double)(color_int / 256 / 256 % 256) / 255.0;
	return (color);
}

t_object		get_object(char *line)
{
	char		**object;
	t_object	tmp;

	object = ft_strsplit(line, ' ');
	tmp.type = ft_atoi(object[0]);
	tmp.coord.x = ft_atoi(object[1]);
	tmp.coord.y = ft_atoi(object[2]);
	tmp.coord.z = ft_atoi(object[3]);
	tmp.vector.x = ft_atoi(object[4]);
	tmp.vector.y = ft_atoi(object[5]);
	tmp.vector.z = ft_atoi(object[6]);
	tmp.radius = ft_atoi(object[7]);
	tmp.color = get_hex_color(object[8]);
	free_split(object);
	return (tmp);
}

void			make_scene(t_env *e, char *buf)
{
	char		**line;
	int			i;
	int			j;

	line = ft_strsplit(buf, '\n');
	e->nb_obj = ft_atoi(line[0]);
	e->obj = (t_object *)malloc(sizeof(t_object) * e->nb_obj);
	i = 1;
	j = -1;
	while (++j < e->nb_obj)
	{
		while (line[i][0] == '/' || line[i][0] == '\n' || line[i][0] == '*')
			i++;
		e->obj[j] = get_object(line[i]);
		i++;
	}
	free_split(line);
}

void			read_scene(t_env *e, char *file)
{
	int			fd;
	int			ret;
	char		*buf;

	buf = (char *)malloc(sizeof(char) * BUF_SIZE);
	if ((fd = open(file, O_RDONLY)) == -1)
		error("Error: Open failed.");
	if ((ret = read(fd, buf, BUF_SIZE)) == -1)
		error("Error: Read failed");
	else if (ret == BUF_SIZE)
		error("Error: Read failed (Too many elements in the scene).");
	make_scene(e, buf);
	if (close(fd) == -1)
		error ("Error: Close failed");
	free(buf);
}

