/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:46:51 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/24 21:08:48 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

struct	s_flags	*init_flags(void)
{
	flag.zero = 32;
	flag.width = 0;
	flag.precision = 0;
	flag.minus = 0;
	flag.dot = 0;
	flag.conversion = 0;
	flag.negative = 1;
	return (&flag);
}

int				check_flags(struct s_flags *flag)
{
	if (flag->zero != 32 || flag->width || flag->precision || \
		flag->precision || flag->minus || flag->dot || flag->conversion)
	{
		return (1);
	}
	return (0);
}

void			print_flags(struct s_flags *flag)
{
	printf("\n******* flags ******\n");
	printf("zero: %d\n", flag->zero);
	printf("width: %d\n", flag->width);
	printf("precision: %d\n", flag->precision);
	printf("minus: %d\n", flag->minus);
	printf("dot: %d\n", flag->dot);
	printf("conversion: %d\n", flag->conversion);
	printf("negative: %d\n", flag->negative);
	printf("******* end flags ******\n");
}

int				valid_input(char **str)
{
	if ((**str != ' ') && (**str != '%') && (**str != '+') && \
		(**str != '-') && (**str != '0') && (**str != '*') && \
		(**str != '.') && (**str != 'c') && (**str != 'd') && \
		(**str != 'i') && (**str != 's') && (**str != 'x') && \
		(**str != 'X') && (**str != 'p') && (**str != 'u') && \
		(ft_isdigit(**(str)) != 1) && (**str != '\0'))
		return (1);
	else
		return (0);
}

int				decode_conversion(char *str)
{
	if (DEBUG)
		printf("\nDEBUG MODE: Input data to decode_operation: %c\n", *str);
	if (*str == 'c')
		return (CHAR);
	else if (*str == 's')
		return (STRING);
	else if (*str == 'p')
		return (POINTER);
	else if (*str == 'u')
		return (U_INTEGER);
	else if (*str == 'i' || *str == 'd')
		return (INTEGER);
	else if (*str == 'x')
		return (HEX);
	else if (*str == 'X')
		return (HEX_UPPER);
	else if (*str == '%')
		return (PERCENT);
	else
		return (-1);
}
