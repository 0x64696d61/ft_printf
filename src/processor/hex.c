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
	unsigned int num;
	char *string;
	int size;

	num = (unsigned int) va_arg(*ap, unsigned long long);
	string = ft_base_converter(num, 16);

	if (flag->conversion == HEX_UPPER)
		string = ft_strtoupper(string);

	string = int_string_builder(string, flag);
	ft_putstr(string);
	size = ft_strlen(string);
	free(string);

	return (size);
}
