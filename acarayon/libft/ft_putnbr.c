/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:23:25 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:24:40 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nbr, int fd)
{
	if (nbr < 0)
	{
		ft_putchar('-', fd);
		nbr = nbr * -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, fd);
	ft_putchar((nbr % 10) + '0', fd);
}
