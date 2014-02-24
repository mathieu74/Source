/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:32:29 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 16:04:24 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

void	raytracing(t_rt *s_rt);
void	get_rgb(t_infos *s_infos, short mode);
void	equation_sec(t_eq *s_eq, t_infos *s_infos);
void	rotation(t_coords *s_rot, t_coords *s_vec, short mode);
void	texture_color(t_object *, t_coords *, int);
void	lum(t_rt *s_rt, t_object *s_object, t_infos *s_infos);
void	shadow(t_rt *s_rt, t_object *s_object, t_infos *s_infos);
t_infos	get_object_infos(t_rt *s_rt, t_object *s_object, t_coords *s_eye,
							t_coords *s_vec);
t_infos	sphere(t_rt *s_rt, t_object *s_object, t_coords *s_eye,
				t_coords *s_vec);
t_infos	cylindre(t_rt *s_rt, t_object *s_object, t_coords *s_eye,
				 t_coords *s_vec);

#endif /* !RAYTRACING_H */
