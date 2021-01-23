/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:59:35 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/23 18:21:12 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	draw_hex(struct s_flags *flag, va_list *ap)
{
	unsigned long long num;
	char *string;

	num = va_arg(*ap, unsigned long long);
	string = ft_base_converter(num, 16);

	if (flag->conversion == HEX_UPPER)
		string = ft_strtoupper(string);

	if ((flag->precision) &&  ((flag->precision) <= (int) ft_strlen(string)))
		flag->precision = (int) ft_strlen(string);
	string = int_string_builder(string, flag);
	ft_putstr(string);
	free(string);
	return (ft_strlen(string));
}
