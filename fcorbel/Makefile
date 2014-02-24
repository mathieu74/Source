#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/04 10:46:59 by fcorbel           #+#    #+#              #
#    Updated: 2014/02/16 16:31:27 by fcorbel          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
.PHONY: all $(NAME) clean fclean re

NAME = rtv1
SRCS = main_rtv1.c \
	   init_e.c \
	   read_scene.c \
	   draw.c \
	   vector_operations.c \
	   vector_functions.c \
	   compute.c \
	   light.c \
	   shape.c \
	   ft_strsplit.c \
	   ft_atoi.c

OBJ  = $(SRCS:.c=.o)
HEAD = header_rtv1.h

FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -L/usr/X11/lib/ -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -g -o $@ $^ -I /usr/X11/include/ $(FLAGS_MLX)
	@echo "$(NAME) : done."

%.o:%.c
	@gcc $(FLAGS) -c -o $@ $< -I /usr/X11/include/

clean:
	@rm -f $(OBJ)
	@echo ".o     : deleted."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) : deleted."

re: fclean all

