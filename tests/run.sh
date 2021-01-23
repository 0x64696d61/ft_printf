#!/usr/bin/env bash

#cd $PROJECT_DIR; make re; cd $PROJECT_DIR/tests && gcc main.c ../libftprintf.a -o ft_printf && ./ft_printf

gcc tests/main.c libftprintf.a -o tests/ft_printf && ./tests/ft_printf
#gcc tests/main.c -fsanitize=address -fsanitize=undefined -g libftprintf.a -o tests/ft_printf && ./tests/ft_printf
