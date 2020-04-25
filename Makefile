# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saopaulo42 <saopaulo42@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 15:44:42 by gariadno          #+#    #+#              #
#    Updated: 2020/04/25 12:31:49 by saopaulo42       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

LIB		=	libft.a

SRC_DIR	=	./src/

LIB_DIR	=	./libft

OBJ_DIR	=	./obj

CC		=	gcc -Wall -Wextra -Werror

INCLUDE	=	libftprintf.h

SRC		=	$(SRC_DIR)ft_print_percent.c	\
			$(SRC_DIR)ft_print_di.c			\
			$(SRC_DIR)ft_print_c.c			\
			$(SRC_DIR)ft_print_u.c			\
			$(SRC_DIR)ft_print_x.c			\
			$(SRC_DIR)ft_print_s.c			\
			$(SRC_DIR)ft_print_p.c			\
			$(SRC_DIR)ft_printf.c			\
			$(SRC_DIR)ft_addpads.c			\
			$(SRC_DIR)ft_itoa_base.c		\
			$(SRC_DIR)ft_putchr.c			\
			$(SRC_DIR)ft_putstr.c

SRC_OB	=	$(SRC_DIR)ft_print_percent.o	\
			$(SRC_DIR)ft_print_di.o			\
			$(SRC_DIR)ft_print_c.o			\
			$(SRC_DIR)ft_print_u.o			\
			$(SRC_DIR)ft_print_x.o			\
			$(SRC_DIR)ft_print_s.o			\
			$(SRC_DIR)ft_print_p.o			\
			$(SRC_DIR)ft_printf.o			\
			$(SRC_DIR)ft_addpads.o			\
			$(SRC_DIR)ft_itoa_base.o		\
			$(SRC_DIR)ft_putchr.o			\
			$(SRC_DIR)ft_putstr.o

OBJ		=	$(SRC:.c=.o)


all		:	$(NAME)

$(NAME)	:	$(LIB) $(OBJ)
			ar rcs $(NAME) $(SRC_OB)

$(LIB)	:	
			$(MAKE) -C $(LIB_DIR)
			cp $(LIB_DIR)/$(LIB) $(NAME)

clean	:
			$(MAKE) clean -C $(LIB_DIR)
			/bin/rm -f $(SRC_OB)

fclean	:	clean
			$(MAKE) fclean -C $(LIB_DIR)
			/bin/rm -f $(NAME)

re		:	fclean all