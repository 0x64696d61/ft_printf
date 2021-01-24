/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:59:48 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/24 22:20:24 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	run_processor(struct s_flags *flag, va_list *ap)
{
	int size;

	size = 0;
	if (flag->width == -1)
		flag->width = va_arg(*ap, int);
	if (flag->precision == -1)
		flag->precision = va_arg(*ap, int);
	if (flag->conversion == CHAR)
		size = draw_char(flag, ap);
	else if (flag->conversion == STRING)
		size = draw_string(flag, ap);
	else if (flag->conversion == U_INTEGER)
		size = draw_u_integer(flag, ap);
	else if (flag->conversion == INTEGER)
		size = draw_integer(flag, ap);
	else if (flag->conversion == POINTER)
		size = draw_pointer(flag, ap);
	else if (flag->conversion == HEX || flag->conversion == HEX_UPPER)
		size = draw_hex(flag, ap);
	else if (flag->conversion == PERCENT)
		size = draw_percent(flag);
	else
		printf("Error\n");
	return (size);
}

char	*fill_line(char *string, int offset, struct s_flags flag)
{
	char	*str;
	char	*str1;

	if (!string)
		return (string);
	//// FIX ME
	str = malloc(sizeof(char*) * offset + 1);
	if (str == NULL)
		return (NULL);
	str[offset] = '\0';
	ft_memset(str, flag.zero, offset);
	if (flag.minus)
		str1 = ft_strjoin(string, str);
	else
		str1 = ft_strjoin(str, string);
	free(str);
	free(string);
	return (str1);
}

char	*string_builder(char *string, struct s_flags *flag)
{
	int	offset;

	if (flag->precision)
		if (((int)ft_strlen(string) > flag->precision))
			string[flag->precision] = '\0';
	if (flag->width)
	{
		if ((flag->width < 0) && ((flag->width + (int)ft_strlen(string)) < 0))
		{
			flag->minus = 1;
			offset = (flag->width + (int)ft_strlen(string)) * -1;
			string = fill_line(string, offset, *flag);
		}
		else if ((offset = flag->width - (int)ft_strlen(string)) > 0)
			string = fill_line(string, offset, *flag);
	}
	return (string);
}
