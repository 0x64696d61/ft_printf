#!/usr/bin/env bash
PROJECT_DIR="/Users/drakosa/dev/school21/projects/ft_printf"

cd $PROJECT_DIR; make re; cd $PROJECT_DIR/tests && gcc main.c ../libftprintf.a -o ft_printf && ./ft_printf
