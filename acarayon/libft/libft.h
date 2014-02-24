/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:19:06 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 12:56:59 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int			atoi_base(char *str, char *base);
int			ft_strlen(char *str, char end);
int			power(int nbr, int pwr);
int			ft_strcmp(char *str1, char *str2, char end);
void		ft_putnbr(int nbr, int fd);
void		ft_putchar(char c, int output);
void		ft_putstr(char *str, int output);

#endif
