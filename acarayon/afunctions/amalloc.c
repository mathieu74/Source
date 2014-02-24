/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:04:50 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:38:22 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*amalloc(int size)
{
	void	*memory;

	if ((memory = malloc(size)) == NULL)
	{
		ft_putstr("Malloc error.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (memory);
}
