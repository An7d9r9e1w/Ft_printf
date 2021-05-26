# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnamor <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 10:22:26 by nnamor            #+#    #+#              #
#    Updated: 2021/04/27 11:57:19 by nnamor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_itoa.c			ft_uitoa.c		ft_uitohex.c	\
		  str.c				print_int.c		print_hex.c		\
		  print_char.c		set_attr.c		conversion.c	\

OBJS	= ${SRCS:.c=.o}

BSRCS	= set_attr_bonus.c	print_float_bonus.c				\
		  ftoa_bonus.c										\

BOBJS	= ${BSRCS:.c=.o}

HEADS	= libftprintf.h		\
		  inc/ft_printf.h	\
		  inc/lib.h			\
		  inc/print.h		\
		  inc/set_attr.h	\
		  inc/ftoa_bonus.h	\

NAME	= libftprintf.a

CC		= gcc

AR		= ar rcs

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f



${NAME}:	ft_printf.o ${OBJS}
			${AR} $@ $^

all:		${NAME}

bonus:		ft_printf_bonus.o ${OBJS} ${BOBJS}
			${RM} ${NAME}
			${AR} ${NAME} $^

%.o:		src/%.c	${HEADS}
			${CC} ${CFLAGS} -I inc -o $@ -c $<

clean:
			${RM} ${OBJS} ${BOBJS} ft_printf.o ft_printf_bonus.o

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
