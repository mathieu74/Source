/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:41:02 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 17:41:05 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_count(const char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	return (nbr);
}

int		ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	if (str[i] == '+')
	{
		if (sign == -1)
			return (0);
		i++;
	}
	return (ft_atoi_count(&(str[i])) * sign);
}
