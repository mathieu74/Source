/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:52:15 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 13:22:38 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "typedef.h"
#include "get_next_line.h"
#include "load_scene.h"
#include "afunctions.h"
#include "libft.h"
#include "macros.h"

void	file_error(void)
{
	ft_putstr("File error.\n", 2);
	exit(EXIT_FAILURE);
}

void	fill_struct_s_coords(t_coords *s_coords, int fd)
{
	char		*line;

	if ((line = get_next_line(fd, '\n')) == NULL)
		file_error();
	s_coords->x = atoi_base(line, DEC);
	if ((line = get_next_line(fd, '\n')) == NULL)
		file_error();
	s_coords->y = atoi_base(line, DEC);
	if ((line = get_next_line(fd, '\n')) == NULL)
		file_error();
	s_coords->z = atoi_base(line, DEC);
}

void	load_scene(t_rt *s_rt, char **argv)
{
	int		fd_objects;
	int		fd_spots;

	s_rt->s_object = NULL;
	s_rt->s_spot = NULL;
	fd_objects = aopen(argv[1], O_RDONLY);
	if ((s_rt->s_object = get_objects(s_rt, fd_objects)) == NULL)
		file_error();
	fd_spots = aopen(argv[2], O_RDONLY);
	if ((s_rt->s_spot = get_spots(fd_spots)) == NULL)
		file_error();
	aclose(fd_spots);
	aclose(fd_objects);
}
