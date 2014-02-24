/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amlx_new_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:00:41 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:39:47 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft.h"

void	*amlx_new_window(void *mlx_ptr, int width, int height, char *name)
{
	void		*win_ptr;

	win_ptr = mlx_new_window(mlx_ptr, width, height, name);
	if (win_ptr == NULL)
	{
		ft_putstr("Mlx_new_window error.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (win_ptr);
}

