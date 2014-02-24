/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:20:06 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:20:20 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen(char *str, char end)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != end)
		i++;
	return (i);
}