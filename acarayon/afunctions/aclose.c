/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aclose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:47:08 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:38:00 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	aclose(int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr("Close error.\n", 2);
		exit(EXIT_FAILURE);
	}
}
