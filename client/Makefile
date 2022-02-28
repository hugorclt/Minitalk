# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:43:36 by hrecolet          #+#    #+#              #
#    Updated: 2022/01/11 11:49:51 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	client.c ../printf/ft_utils_char.c ../printf/ft_printf_utils.c \
				../printf/ft_printf.c ../printf/ft_utils_len.c ../printf/ft_utils_putnbr.c

NAME		=	client

OBJS		=	ft_printf_utils.o ft_printf.o ft_utils_char.o ft_utils_char.o \
				ft_utils_putnbr.o ft_utils_len.o
				
OBJ			=	${SRCS:.c=.o}

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				gcc -o $(NAME) $(OBJ)

clean		:
				/bin/rm -f $(OBJ) $(OBJS)

fclean		:	clean
				/bin/rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean norme fclean re
