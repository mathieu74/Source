#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarayon <acarayon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/14 19:41:22 by acarayon          #+#    #+#              #
#    Updated: 2014/02/16 13:13:10 by acarayon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	libafunctions.a

SRC =	./aclose.c			\
		./amalloc.c			\
		./amlx_get_data_addr.c		\
		./amlx_init.c			\
		./amlx_new_image.c		\
		./amlx_new_window.c		\
		./amlx_xpm_file_to_image.c	\
		./aopen.c			\
		./aread.c			\
		./awrite.c

OBJ =	$(SRC:.c=.o)

CFLAGS +=	-I../includes -Wall -Wextra -Werror

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
