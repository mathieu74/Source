/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:20:45 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:21:00 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		power(int nbr, int pwr)
{
	if (pwr > 1)
	{
		nbr = nbr * power(nbr, pwr - 1);
		return (nbr);
	}
	else if (pwr == 1)
		return (nbr);
	else if (pwr == 0)
		return (1);
	return (0);
}
