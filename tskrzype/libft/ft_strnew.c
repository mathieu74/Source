/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:08:14 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 18:08:18 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	n;

	n = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		while (n < size)
		{
			str[n] = '\0';
			n++;
		}
		str[n] = '\0';
		return (str);
	}
	else
		return (NULL);
}
