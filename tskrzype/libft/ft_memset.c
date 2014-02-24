/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:46:54 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 17:46:58 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str2;

	str2 = (unsigned char *)b;
	if (str2 == NULL)
		return (0);
	while (len > 0)
	{
		len--;
		str2[len] = c;
	}
	return (str2);
}
