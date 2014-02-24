/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:46:36 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 17:46:39 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void		ft_memmove_first(char *s1, const char *s2, size_t n)
{
	int	a;

	a = n - 1;
	while (a >= 0)
	{
		s1[a] = s2[a];
		a--;
	}
}

static void		ft_memmove_second(char *s1, const char *s2, size_t n)
{
	int	a;

	a = 0;
	while (a < (int)n)
	{
		s1[a] = s2[a];
		a++;
	}
}

void			*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*tmp1;
	const char	*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	if (&(tmp2[n]) >= &(tmp1[0]) && &(tmp1[0]) >= &(tmp2[0]))
		ft_memmove_first(s1, s2, n);
	else if (&(tmp1[n]) >= &(tmp2[0]) && &(tmp1[0]) <= &(tmp2[0]))
		ft_memmove_second(s1, s2, n);
	else if (&(tmp2[n]) <= &(tmp1[0]) || &(tmp1[n]) <= &(tmp2[0]))
		ft_memcpy(s1, s2, n);
	return (s1);
}
