/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afunctions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:47:23 by acarayon          #+#    #+#             */
/*   Updated: 2014/02/16 12:07:09 by acarayon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFUNCTIONS_H
# define AFUNCTIONS_H

int			aopen(char *path, int flags);
int			aread(int fd, void *buffer, int count);
char		*amlx_get_data_addr(void *img_ptr , int *bits_per_pixel,
								int *size_line, int *endian);
void		aclose(int fd);
void		*amlx_init(void);
void		*amlx_new_image(void *mlx_ptr, int width, int height);
void		*amlx_new_window(void *mlx_ptr, int width, int height, char *name);
void		*amlx_xpm_file_to_image	(void *mlx_ptr, char *filename, int width,
									int height);
void		awrite(int fd, void *buffer, int count);
void		*amalloc(int size);

#endif /* !AFUNCTIONS_H */
