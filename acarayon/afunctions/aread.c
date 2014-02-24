/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aread.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:55:23 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:41:40 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	aread(int fd, void *buffer, int count)
{
	int	read_char;

	if ((read_char = read(fd, buffer, count)) == -1)
	{
		ft_putstr("Read error.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (read_char);
}
