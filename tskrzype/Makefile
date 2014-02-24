# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/10 15:19:38 by tskrzype          #+#    #+#              #
#    Updated: 2014/02/16 20:00:56 by tskrzype         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean re libft

NAME = rtv1

FLG = -Wall -Wextra -Werror

AFG = $(FLG) -ansi -pedantic

CC = gcc $(FLG)

LIBX = -L /usr/X11/lib -lmlx -lXext -lX11

LIBLFT = -L $(DLIB) -lft

DINC = ./includes/
DSRC = ./srcs/
DLIB = ./libft/
DOBJ = ./objs/
MAIN = ./

SRC = main.c \
	  ft_get_index.c \
	  ft_put_pixel_sphere.c \
	  ft_get_light.c \
	  ft_plan.c \
	  ft_hook.c \
	  ft_ray.c \
	  ft_cylindre.c

OBJ = $(patsubst %.c, $(DOBJ)%.o, $(SRC))

all: libft $(NAME)

$(DOBJ)%.o: $(MAIN)%.c
	/bin/mkdir -p $(DOBJ)
	$(CC) -o $@ -c $< -I $(DINC) -g

$(DOBJ)%.o: $(DSRC)%.c
	/bin/mkdir -p $(DOBJ)
	$(CC) -o $@ -c $< -I $(DINC) -g

$(NAME): $(DLIB)libft.a $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBLFT) $(LIBX) -g

libft:
	make -C $(DLIB)

clean:
	make -C $(DLIB) clean
	/bin/rm -Rf $(DOBJ)

fclean: clean
	make -C $(DLIB) fclean
	/bin/rm -f $(NAME)

re: fclean all
