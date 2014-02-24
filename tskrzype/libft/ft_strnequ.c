/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:07:59 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 18:08:01 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	z;
	int		value;

	z = 0;
	value = 0;
	while (z < n && s1[z] == s2[z] && s1[z]  && s2[z])
		z++;
	if (z < n && s1[z] != s2[z])
		return (0);
	return (1);
}
