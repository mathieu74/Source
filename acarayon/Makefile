#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/14 18:50:08 by acarayon          #+#    #+#              #
#    Updated: 2014/02/17 12:45:22 by mmole            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	rtv1

SRC =	./equation_sec.c \
		./get_next_line.c \
		./get_objects.c \
		./get_spots.c \
		./load_scene.c \
		./get_texture.c \
		./lum.c \
		./ft_pixel_put_to_image.c \
		./raytracing.c \
		./rotation.c \
		./rt.c \
		./sphere.c \


OBJ =	$(SRC:.c=.o)

CFLAGS =	-I./includes -Wall -Wextra -Werror

LDFLAGS =	-L./libft -L./afunctions -llibft -lafunctions -L/usr/X11/lib -lXext -lX11 -lmlx -lm

RM =	rm -f

$(NAME) :	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean :
		$(RM)	$(OBJ)

fclean :	clean
		$(RM)	$(NAME)

re :	fclean all

all :	$(NAME)

.PHONY :	clean all fclean re
