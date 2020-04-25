# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 13:20:32 by gariadno          #+#    #+#              #
#    Updated: 2020/04/25 12:34:54 by saopaulo42       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

FILES		=	ft_isdigit.c	\
				ft_strlen.c		\
				ft_strchr.c		\
				ft_itoa.c

OBJ			=	$(FILES:.c=.o)

OBJ			=	ft_isdigit.o	\
				ft_itoa.o	\
				ft_strlen.o	\
				ft_strchr.o

CC			=	gcc -c -Wall -Werror -Wextra

INCLUDES	=	libft.h

RM			=	/bin/rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(INCLUDES)
			ar rcs $(NAME) $(OBJ)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
