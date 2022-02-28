# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 13:39:38 by hrecolet          #+#    #+#              #
#    Updated: 2021/11/30 19:02:35 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c ft_utils_char.c ft_utils_putnbr.c ft_utils_len.c \
				ft_printf_utils.c \

NAME		=	libftprintf.a

OBJ			=	*.o

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				ar rc $(NAME) $(OBJ)
$(OBJ)		:
				gcc -Wall -Wextra -Werror -c $(SRCS)

clean		:
				/bin/rm -f $(OBJ)

fclean		:	clean
				/bin/rm -f $(NAME)

re			:	fclean all


.PHONY		:	all clean norme fclean re
