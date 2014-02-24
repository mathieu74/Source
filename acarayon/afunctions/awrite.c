/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awrite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:03:48 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:29:02 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	awrite(int fd, void *buffer, int count)
{
	if (write(fd, buffer, count) == -1)
	{
		write(2, "Write error.\n", ft_strlen("Write error.\n", '\0'));
		exit(EXIT_FAILURE);
	}
}
