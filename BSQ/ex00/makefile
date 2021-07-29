SRCS	= ft_is_printable.c ft_putchar.c ft_putstr.c ft_read.c ft_solve.c ft_strcmp.c ft_strlen.c main.c ft_read_standard.c ft_read2.c ft_solve2.c

NAME	= bsq

FLAGS	= -Wall -Wextra -Werror

CC		= gcc

RM		= rm -f

all :       $(NAME)

$(NAME) :
			$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean :
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
