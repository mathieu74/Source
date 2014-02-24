/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:21:35 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:22:46 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strcmp(char *str1, char *str2, char end)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != end && str1[i] &&
			str2[i] != end && str2[i])
		i++;
	if ((str1[i] == '\0' && str2[i] == '\0') ||(str1[i] == end &&
		str2[i] == end))
		return (0);
	return (str1[i] - str2[i]);
}
