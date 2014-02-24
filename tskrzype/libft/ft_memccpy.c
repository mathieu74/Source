/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:44:09 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 17:44:13 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*tmp1;
	const char	*tmp2;
	int			i;

	tmp1 = (char*)s1;
	tmp2 = (char*)s2;
	i = 0;
	while (n != 0)
	{
		tmp1[i] = tmp2[i];
		if (tmp2[i] == (unsigned char)c)
			return (&(tmp1[i + 1]));
		i++;
		n--;
	}
	return (NULL);
}
