/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:06:46 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 18:06:48 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	z;

	z = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)));
	while (s[z] != '\0')
	{
		str[z] = f(z, *(&(s[z])));
		z++;
	}
	return (str);
}
