/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:06:32 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 18:06:36 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		z;

	z = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)));
	while (s[z] != '\0')
	{
		str[z] = f(*(&(s[z])));
		z++;
	}
	return (str);
}
