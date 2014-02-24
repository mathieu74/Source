/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:09:19 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 18:09:22 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	n;
	int	k;

	i = 0;
	n = 0;
	k = 0;
	if (s2[n] == '\0')
		return ((char*)s1);
	while (s1[i])
	{
		n = 0;
		k = 0;
		while (s1[i + k] == s2[n] && s2[n] != '\0')
		{
			k++;
			n++;
		}
		if (s2[n] == '\0')
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
