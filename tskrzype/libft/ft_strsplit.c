/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:08:55 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 18:08:59 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**ft_create_tab(char const *s, char c)
{
	int		n;
	int		number_str;
	char	**tmp;
	char	*tmp1;

	n = 0;
	number_str = 0;
	while (s[n])
	{
		while (s[n] == c)
			n++;
		if (s[n] != '\0')
		{
			number_str++;
			while (s[n] != c && s[n])
				n++;
		}
	}
	tmp = (char**)malloc(sizeof(char*) * (number_str + 1));
	tmp1 = (char*)malloc(sizeof(char));
	tmp1 = '\0';
	tmp[number_str] = tmp1;
	return (tmp);
}

static char	*ft_create_str(char const *s, char c, int *n)
{
	int		n_bis;
	char	*str;
	int		index_str;

	index_str = 0;
	n_bis = *n;
	while (s[*n] == c)
		*n = *n + 1;
	n_bis = *n;
	while (s[n_bis] != '\0' && s[n_bis] != c)
		n_bis++;
	str = (char*)malloc(sizeof(char) * (n_bis - *n) + 1);
	while (*n < n_bis)
	{
		str[index_str] = s[*n];
		index_str++;
		*n = *n + 1;
	}
	str[index_str] = '\0';
	return (str);
}

static char	**ft_fill_tab(char const *s, char c, char **tmp)
{
	int		index_str_tab;
	int		n;

	index_str_tab = 0;
	n = 0;
	while (s[n])
	{
		while (s[n] == c)
			n++;
		if (s[n] != '\0')
		{
			tmp[index_str_tab] = ft_create_str(s, c, &n);
			index_str_tab++;
		}
	}
	return (tmp);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tmp;

	tmp = ft_create_tab(s, c);
	tmp = ft_fill_tab(s, c, tmp);
	return (tmp);
}
