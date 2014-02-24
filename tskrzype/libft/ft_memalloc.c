/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:43:47 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 17:43:53 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*mem;
	unsigned int	i;

	mem = malloc(size);
	i = 0;
	if (mem)
	{
		ft_memset(mem, 0, size);
		return (mem);
	}
	else
		return (NULL);
}
