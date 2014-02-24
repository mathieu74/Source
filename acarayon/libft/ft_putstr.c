/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:25:35 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/14 20:26:12 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "afunctions.h"

void	ft_putstr(char *str, int output)
{
	awrite(output, str, ft_strlen(str, '\0'));
}
