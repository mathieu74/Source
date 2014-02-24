/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:51:09 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 13:25:20 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "get_next_line.h"
#include "afunctions.h"

static char		*get_next_line_core(const int fd, const char end_line,
									t_gnl *s_gnl)
{
	int					i;

	if (s_gnl->read_char != 0)
	{
		i = 0;
		while (s_gnl->pos < s_gnl->read_char &&
				s_gnl->pos != 0 && s_gnl->buffer[s_gnl->pos] != end_line)
			s_gnl->line[i++] = s_gnl->buffer[s_gnl->pos++];
		while (s_gnl->read_char != 0 && i < READ_MAX &&
				s_gnl->buffer[s_gnl->pos] != end_line)
		{
			s_gnl->pos = 0;
			s_gnl->read_char = aread(fd, s_gnl->buffer, READ);
			while (s_gnl->pos < s_gnl->read_char &&
					i < READ_MAX && s_gnl->buffer[s_gnl->pos] != end_line)
				s_gnl->line[i++] = s_gnl->buffer[s_gnl->pos++];
		}
		s_gnl->line[i] = '\0';
		while (s_gnl->buffer[s_gnl->pos] == end_line)
			s_gnl->pos++;
		return (s_gnl->line);
	}
	return (NULL);
}

char			*get_next_line(const int fd, const char end_line)
{
	static t_tab_gnl	s_tab_gnl[2];
	static short		toggle = 0;

	if (toggle == 0)
	{
		s_tab_gnl[0].fd = -1;
		s_tab_gnl[0].s_gnl.read_char = READ;
		s_tab_gnl[0].s_gnl.pos = 0;
		s_tab_gnl[1] = s_tab_gnl[0];
		toggle = 1;
	}
	if (s_tab_gnl[0].fd == -1 || s_tab_gnl[0].fd == fd)
	{
		if (s_tab_gnl[0].fd == -1)
			s_tab_gnl[0].fd = fd;
		return (get_next_line_core(fd, end_line, &s_tab_gnl[0].s_gnl));
	}
	else if (s_tab_gnl[1].fd == -1 || s_tab_gnl[1].fd == fd)
	{
		if (s_tab_gnl[1].fd == -1)
	s_tab_gnl[1].fd = fd;
		return (get_next_line_core(fd, end_line, &s_tab_gnl[1].s_gnl));
	}
	return (NULL);
}
