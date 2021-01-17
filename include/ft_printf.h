/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:13:32 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/17 20:21:53 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define DEBUG 0
# define FT_PRINTF_H
# include <unistd.h> //read || close || write
# include <fcntl.h> // open || O_RDONLY
# include <stdlib.h> // malloc
# include <stdio.h>
# include <string.h> // hz
# include <stdarg.h> // va_start, va_arg, va_copy and va_end
# include "../libft/libft.h"
# include "ft_conversions.h"

struct	s_flags
{
	int minus;
	int zero;
	int dot;
	int precision;
	int width;
	/* 1 - c; 2 - s; 3 - p; 4 - d
		5 - i; 6 - u; 7 - x; 8 - X */
	int conversion;
} flag;

int ft_printf(char *str, ...);
void print_flags(struct s_flags *flag);
struct s_flags *init_flags();
struct s_flags *line_parser(char **str, struct s_flags *flag);
int decode_operation(char *str);
void run_processor(struct s_flags *flag, va_list *ap);
int check_flags(struct s_flags *flag);
void draw_string(struct s_flags *flag, va_list *ap);
void draw_integer(struct s_flags *flag, va_list *ap);

#endif
