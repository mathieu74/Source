/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:04:29 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 18:04:32 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	z;

	z = 0;
	while (s1[z] && s2[z])
	{
		if (s1[z] == s2[z])
			z++;
		else
			return (0);
	}
	if (s1[z] != s2[z])
		return (0);
	return (1);
}
