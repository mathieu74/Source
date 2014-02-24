/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:44:34 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 17:44:38 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*tmp;

	tmp = s;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == c)
			return ((void*)tmp + i);
		i++;
	}
	return (NULL);
}
