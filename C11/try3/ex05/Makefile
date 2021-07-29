# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchevill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 16:20:57 by vchevill          #+#    #+#              #
#    Updated: 2021/07/29 10:15:30 by vchevill         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_operations.c ft_putchar.c ft_putnbr.c ft_putstr.c main.c

OBJS = ${SRCS:.c=.o}

NAME = do-op

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
						${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
						${CC} -o ${NAME} ${CFLAGS} ${OBJS}

all:			${NAME}

clean :		
				${RM} ${OBJS}

fclean :		clean
					${RM} ${NAME}
			
re: fclean all


.PHONY: all clean fclean re
