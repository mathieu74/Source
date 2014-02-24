#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/14 20:11:50 by acarayon          #+#    #+#              #
#    Updated: 2014/02/16 13:12:08 by acarayon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	liblibft.a

SRC =	./atoi_base.c \
		./ft_putchar.c \
		./ft_putnbr.c \
		./ft_putstr.c \
		./ft_strlen.c \
		./power.c \
		./ft_strcmp.c

OBJ =	$(SRC:.c=.o)

CFLAGS =	-I../includes -Wall -Wextra -Werror

RM =	rm -f

$(NAME) :	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean :
		$(RM)	$(OBJ)

fclean :	clean
		$(RM)	$(NAME)

re :	fclean all

all :	$(NAME)

.PHONY :	clean all fclean re
