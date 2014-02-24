/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aopen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:53:32 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:41:24 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

int	aopen(char *path, int flags)
{
	int		fd;

	if ((fd = open(path, flags)) == -1)
	{
		ft_putstr("Open error.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
