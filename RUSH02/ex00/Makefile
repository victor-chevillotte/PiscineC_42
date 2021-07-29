NAME = rush-02

SRC = ft_atoi.c ft_check_dic.c ft_checkargs.c ft_is_printable.c ft_parse_dictionnary.c ft_putchar.c ft_putstr.c ft_recursive_read.c ft_strcmp.c ft_strlen.c ft_searchdiv.c ft_putnbr.c ft_read_file.c ft_strdup.c ft_parse_line.c ft_print.c main.c

OBJS = ${SRC: .c=.o}

NAMEX: ${OBJS}
	gcc -o ${NAME} ${OBJS}

clean :
	rm -f *.o

fclean : clean
	rm -f ${NAME}
