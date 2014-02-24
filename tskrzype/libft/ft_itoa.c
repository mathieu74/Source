/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:43:26 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 17:43:30 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	charcounter(int n, int *k)
{
	if (n < 0)
	{
		*k = *k + 1;
		n = -n;
	}
	if (n >= 10)
	{
		charcounter(n / 10, k);
		charcounter(n % 10, k);
	}
	else
		*k = *k + 1;
}

static void	put_itoa(char *str, int n, int *k)
{
	if (n < 0)
	{
		str[*k] = '-';
		*k = *k + 1;
		n = -n;
	}
	if (n >= 10)
	{
		put_itoa(str, n / 10, k);
		put_itoa(str, n % 10, k);
	}
	else
	{
		str[*k] = n + 48;
		*k = *k + 1;
	}
}

static void	ft_min_int(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
}

char		*ft_itoa(int n)
{
	int		k;
	int		m;
	char	*str;

	k = 0;
	m = 0;
	if (n == -2147483648)
	{
		str = (char*)malloc(sizeof(char) * 12);
		ft_min_int(str);
	}
	else
	{
		charcounter(n, &k);
		str = (char*)malloc(sizeof(char) * k + 1);
		put_itoa(str, n, &m);
		str[k] = '\0';
	}
	return (str);
}
