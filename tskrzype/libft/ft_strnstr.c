/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:08:28 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 18:08:31 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (s2[j] == '\0')
		return ((char*)s1);
	while (i < n && s1[i])
	{
		j = 0;
		k = 0;
		while (s1[i + k] == s2[j] && s2[j] != '\0' && i + (size_t)k < n)
		{
			k++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
