/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_sec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:16:30 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 12:30:08 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "typedef.h"

static void	delta_neg(t_eq *s_eq, t_infos *s_infos)
{
	s_eq->k1 = 0;
	s_eq->k2 = 0;
	s_infos->k1 = 0;
	s_infos->k2 = 0;
}

static void	delta_equal_zero(t_eq *s_eq, t_infos *s_infos)
{
	s_eq->k1 = (-s_eq->b / (2 * s_eq->a));
	s_eq->k2 = 0;
	s_infos->k1 = s_eq->k1;
	s_infos->k2 = 0;
}

static void	delta_sup_zero(t_eq *s_eq, t_infos *s_infos)
{
	s_eq->k1 = ((-s_eq->b - (sqrt(s_eq->delta))) / (2 * s_eq->a));
	s_eq->k2 = ((-s_eq->b + (sqrt(s_eq->delta))) / (2 * s_eq->a));
	s_infos->k1 = s_eq->k1;
	s_infos->k2 = s_eq->k2;
}

void	equation_sec(t_eq *s_eq, t_infos *s_infos)
{
	s_eq->delta = (s_eq->b * s_eq->b) - (4 * s_eq->a * s_eq->c);
	if (s_eq->delta < 0)
		delta_neg(s_eq, s_infos);
	else if (s_eq->delta >= 0 && s_eq->delta <= 0.000001)
		delta_equal_zero(s_eq, s_infos);
	else if (s_eq->delta >= 0.000001)
		delta_sup_zero(s_eq, s_infos);
}
