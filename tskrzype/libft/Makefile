# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tskrzype <tskrzype@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/16 17:40:48 by tskrzype          #+#    #+#              #
#    Updated: 2014/02/16 17:40:51 by tskrzype         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar.c \
	  ft_putstr.c \
	  ft_putnbr.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strlen.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_strlcat.c \
	  ft_bzero.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_memalloc.c \
	  ft_memcmp.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putendl.c \
	  ft_strcmp.c \
	  ft_strdup.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_tolower.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_strsplit.c \
	  ft_strjoin.c \
	  ft_strsub.c \
	  ft_memchr.c \
	  ft_strcat.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striteri.c \
	  ft_striter.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strtrim.c \
	  ft_itoa.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_strstr.c \
	  get_next_line.c

OBJ = $(SRC:.c=.o)

LIB = ../includes/

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $^ -I $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
