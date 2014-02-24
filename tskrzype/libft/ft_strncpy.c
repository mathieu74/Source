/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:07:38 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 18:07:41 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strncpy(char *s1, char const *s2, size_t n)
{
	size_t	i;
	int		size;

	i = 0;
	size = ft_strlen(s2);
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	if (size < (int)n)
		s1[i] = '\0';
	return (s1);
}
