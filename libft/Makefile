# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 21:08:21 by pstrait           #+#    #+#              #
#    Updated: 2020/11/12 23:38:42 by pstrait          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=*.c
OBJECTS=*.o
INCLUDES=./
# for release
COMPILER_FLAGS=-Wall -Wextra -Werror
# for debugs
#COMPILER_FLAGS=

all: $(NAME)

$(NAME): $(SRCS) libft.h
	@gcc $(COMPILER_FLAGS) -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
