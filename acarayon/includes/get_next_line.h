/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:31:50 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 13:47:37 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define READ 128
# define READ_MAX 256

typedef struct	s_gnl	t_gnl;
typedef struct	s_tab_gnl	t_tab_gnl;

struct			s_gnl
{
	char		line[READ_MAX + 1];
	char		buffer[READ];
	int			read_char;
	int			pos;
};

struct			s_tab_gnl
{
	t_gnl		s_gnl;
	int			fd;
};

char	*get_next_line(const int, const char);

#endif /* !GET_NEXT_LINE_H */
