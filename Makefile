NAME =		libftprintf.a

SRC_DIR =	src/
SRC_FILES =	ft_printf.c \
			parser/parser.c \
			parser/flags_manager.c \
			processor/processor.c \
			processor/string.c \
			processor/integer.c \
			processor/u_integer.c \
			processor/char.c \
			processor/pointer.c \
			processor/percent.c \
			processor/hex.c \
			processor/utill.c

OBJS =		${addprefix ${SRC_DIR},${SRC_FILES:.c=.o}}

CFLAGS = -Wall -Wextra -Werror
# -fsanitize=address -fsanitize=undefined -g

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
	tests/run.sh

all :		${NAME}

clean :
	make clean -C ${LIBDIR}
	rm -f ${OBJS}

fclean :	clean
	make fclean -C ${LIBDIR}
	rm -f ${NAME}

re :	fclean all

.PHONY : all clean fclean re
