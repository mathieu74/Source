/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 12:10:28 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 12:13:29 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_SCENE_H
# define LOAD_SCENE_H

void		file_error(void);
void		fill_struct_s_coords(t_coords *s_coords, int fd);
void		load_scene(t_rt *s_rt, char **argv);
t_spot		*get_spots(int fd);
t_object	*get_objects(t_rt *s_rt, int fd);

#endif /* !LOAD_SCENE_H */
