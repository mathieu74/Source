/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:03:27 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 18:03:31 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	n;

	n = 0;
	while (s1[n] == s2[n])
	{
		if (s1[n + 1] == '\0')
			return (0 - s2[n + 1]);
		if (s2[n + 1] == '\0')
			return (s1[n + 1]);
		n++;
	}
	return (s1[n] - s2[n]);
}
