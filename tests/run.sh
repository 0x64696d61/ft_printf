#!/usr/bin/env bash

#cd $PROJECT_DIR; make re; cd $PROJECT_DIR/tests && gcc main.c ../libftprintf.a -o ft_printf && ./ft_printf

gcc tests/main.c libftprintf.a -o tests/ft_printf && ./tests/ft_printf
#gcc tests/main.c -fsanitize=address -fsanitize=undefined -g libftprintf.a -o tests/ft_printf && ./tests/ft_printf



# - [OUTPUT] ft_printf("%0198.9X%---187.*s%--*.103%%-92.43x" ,3371063919u,-131,"",51,4096758508u)
# - [OUTPUT] ft_printf("%0135.*%%--39c%095.16i%0120.39x%8.33s" ,-193,15,143560664,578664161u,"V0_(")
#
#
# - [OUTPUT] ft_printf("%0198.9X%---187.*s%--*.103%%-92.43x" ,3371063919u,-131,"",51,4096758508u)
# - [OUTPUT] ft_printf("%0135.*%%--39c%095.16i%0120.39x%8.33s" ,-193,15,143560664,578664161u,"V0_(")
#
# - [OUTPUT] ft_printf("%0198.9X%---187.*s%--*.103%%-92.43x" ,3371063919u,-131,"",51,4096758508u)
# - [OUTPUT] ft_printf("%0135.*%%--39c%095.16i%0120.39x%8.33s" ,-193,15,143560664,578664161u,"V0_(")
