/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:13:32 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/23 23:25:41 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define DEBUG 0
# define DEBUG_FLAGS 0
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
	int conversion;
	int negative;
} flag;

int		ft_printf(char *str, ...);
void 	print_flags(struct s_flags *flag);
struct s_flags *init_flags();
struct s_flags *line_parser(char **str, struct s_flags *flag, int *counter);
int 	decode_operation(char *str);
int 	run_processor(struct s_flags *flag, va_list *ap);
int		check_flags(struct s_flags *flag);
int		draw_string(struct s_flags *flag, va_list *ap);
int	 	draw_integer(struct s_flags *flag, va_list *ap);
int		draw_char(struct s_flags *flag, va_list *ap);
int		draw_u_integer(struct s_flags *flag, va_list *ap);
char	*string_builder(char *string, struct s_flags *flag);
char	*fill_line(char *string, int offset, struct s_flags flag);
char	*int_string_builder(char *string, struct s_flags *flag);
int		draw_pointer(struct s_flags *flag, va_list *ap);
int		draw_percent(struct s_flags *flag);
int		draw_hex(struct s_flags *flag, va_list *ap);
int		valid_input(char **str);
int		decode_conversion(char *str);

#endif
