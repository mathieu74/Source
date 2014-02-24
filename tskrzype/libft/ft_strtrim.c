/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:09:53 by tskrzype          #+#    #+#             */
/*   Updated: 2014/02/16 18:09:56 by tskrzype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		ln;
	int		tr_beg;
	int		tr_end;
	char	*str_cpy_s;
	int		ln_t;

	tr_beg = 0;
	tr_end = 0;
	ln = ft_strlen(s);
	ln_t = ln;
	str_cpy_s = ft_strnew(ln);
	while (s[tr_beg] == ' ' || s[tr_beg] == '\n' || s[tr_beg] == '\t')
		tr_beg++;
	while (s[ln_t - 1] == ' ' || s[ln_t - 1] == '\n' || s[ln_t - 1] == '\t')
	{
		ln_t--;
		tr_end++;
	}
	ft_strncpy(str_cpy_s, s + tr_beg, ln - (tr_beg + tr_end));
	return (str_cpy_s);
}
