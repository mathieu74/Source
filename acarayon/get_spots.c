/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:51:48 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 21:25:45 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "typedef.h"
#include "load_scene.h"
#include "get_next_line.h"
#include "afunctions.h"
#include "libft.h"
#include "macros.h"

static void	fill_param(t_spot *s_spot, int fd)
{
	char		*line;

	if ((line = get_next_line(fd, '\n')) == NULL)
		file_error();
	s_spot->color = atoi_base(line, HEX);
}

t_spot	*get_spots(int fd)
{
	t_spot		*s_begin_spot;
	t_spot		*s_ptr_spot;
	char		*line;

	s_begin_spot = NULL;
	while ((line = get_next_line(fd, '\n')) && line[0] == '-')
	{
		s_ptr_spot = amalloc(sizeof(t_spot));
		s_ptr_spot->s_next = s_begin_spot;
		fill_struct_s_coords(&s_ptr_spot->s_trans, fd);
		fill_param(s_ptr_spot, fd);
		s_begin_spot = s_ptr_spot;
	}
	return (s_begin_spot);
}
