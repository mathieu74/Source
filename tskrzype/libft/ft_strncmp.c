/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:07:12 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 18:07:21 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	nb;

	nb = 0;
	while (nb < n && s1[nb] == s2[nb])
	{
		if (s1[nb + 1] == '\0')
			return (0 - s2[nb + 1]);
		if (s2[nb + 1] == '\0')
			return (s1[nb + 1] - 0);
		nb++;
	}
	return (s1[nb] - s2[nb]);
}
