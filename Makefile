# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:10:54 by psaulnie          #+#    #+#              #
#    Updated: 2022/02/14 09:41:54 by psaulnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c srcs/push.c srcs/swap.c srcs/rotate.c \
srcs/reverse_rotate.c srcs/case.c srcs/utils.c
OBJS = ${SRCS:.c=.o}
LIBFT = libft/
LIBFT_LIB = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = push_swap

.PHONY:	all clean fclean re

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT} inc/push_swap.h Makefile
		make -C ${LIBFT}
		${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} -o ${NAME}

clean:
		rm -f ${OBJS}
		make -C ${LIBFT} clean

fclean: clean
		rm -f ${NAME} ${LIBFT_LIB}
		make -C ${LIBFT} fclean

re: fclean all

${LIBFT}:
		make -C ${LIBFT}