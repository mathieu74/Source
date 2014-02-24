/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:06:02 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 18:06:05 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	size_dst;
	int	size_src;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	while (dst[i] != '\0')
		i++;
	while ((size_t)(size_dst + j + 1) < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if ((size_t)size_dst < size)
		return (size_dst + size_src);
	else
		return (size + size_src);
}
