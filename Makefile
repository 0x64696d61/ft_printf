NAME =		libftprintf.a

SRC_DIR =	src/
SRC_FILES =	ft_printf.c ft_parser.c ft_processor.c

OBJS =		${addprefix ${SRC_DIR},${SRC_FILES:.c=.o}}

CFLAGS = -Wall -Wextra -Werror

LIBFT =		libft.a
LIBDIR =	libft

HEADER =	-I include -I ${LIBDIR}

.c.o:
	gcc ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	make -C ${LIBDIR}
	cp ${LIBDIR}/${LIBFT} ${NAME}
	ar -vrc ${NAME} ${OBJS}
	#ar -rcS ${NAME} ${OBJS} ${LIBDIR}/${LIBFT}
#	/Users/pstrait/projects/cmd.sh

all :		${NAME}

clean :
	make clean -C ${LIBDIR}
	rm -f ${OBJS}

fclean :	clean
	make fclean -C ${LIBDIR}
	rm -f ${NAME}

re :	fclean all

.PHONY : all clean fclean re
