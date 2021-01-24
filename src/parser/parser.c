/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:46:27 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/24 21:10:29 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	void	puts_and_count(char **str, int *p_counter)
{
	ft_putchar(**str);
	(*p_counter)++;
	(*str)++;
}

static	void	check_dot(char **str, struct s_flags *flag)
{
	if (**str == '.')
	{
		flag->dot = 1;
		(*str)++;
		if (**str == '*')
		{
			flag->precision = -1;
			(*str)++;
		}
		else if (ft_isdigit(**(str)))
		{
			flag->precision = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
	}
}

static	void	check_star(char **str, struct s_flags *flag)
{
	if (((**str == '*') || (ft_isdigit(**(str)))) && (*((*str) - 1) != '.'))
	{
		if (**str == '*')
		{
			flag->width = -1;
			(*str)++;
		}
		else
		{
			flag->width = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
	}
}

static	void	check_minus_and_zero(char **str, struct s_flags *flag)
{
	if (**str == '-')
	{
		while (**str == '-')
			(*str)++;
		flag->minus = 1;
		flag->zero = ' ';
	}
	else if ((**str == '0') && (flag->minus == 0))
	{
		flag->zero = '0';
		while (**str == '0')
			(*str)++;
		if (**str == '-')
		{
			flag->minus = 1;
			flag->zero = ' ';
			(*str)++;
		}
	}
}

struct	s_flags	*line_parser(char **str, struct s_flags *flag, int *p_counter)
{
	int fl;

	fl = 0;
	while (**str)
		if ((**str == '%') || (fl == 1))
		{
			fl = 1;
			if (**str == '%' && *((*str) + 1) == '%')
			{
				puts_and_count(str, p_counter);
				break ;
			}
			(*str)++;
			while (valid_input(str))
				(*str)++;
			while (**str == ' ' || **str == '+')
				puts_and_count(str, p_counter);
			check_minus_and_zero(str, flag);
			check_star(str, flag);
			check_dot(str, flag);
			flag->conversion = decode_conversion(*str);
			if (flag->conversion != -1)
				break ;
		}
		else
			puts_and_count(str, p_counter);
	return (flag);
}
