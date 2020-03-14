# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gariadno <gariadno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 13:20:32 by gariadno          #+#    #+#              #
#    Updated: 2020/03/13 14:46:29 by gariadno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

OBJ_DIR		=	../obj

FILES		=	ft_isdigit.c	\
				ft_itoa.c		\
				ft_strlen.c

OBJ			=	$(FILES:.c=.o)

OBJ_PATH	=	$(OBJ_DIR)/ft_isdigit.o	\
				$(OBJ_DIR)/ft_itoa.o		\
				$(OBJ_DIR)/ft_strlen.o

CC			=	gcc -c -Wall -Werror -Wextra

INCLUDES	=	libft.h

RM			=	/bin/rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(INCLUDES)
			ar rcs $(NAME) $(OBJ)
			mv $(OBJ) $(OBJ_DIR)

clean	:
			$(RM) $(OBJ_PATH)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
