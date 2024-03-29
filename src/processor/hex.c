/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:59:35 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/24 21:15:30 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	draw_hex(struct s_flags *flag, va_list *ap)
{
	char			*string;
	int				size;
	unsigned int	num;

	num = (unsigned long long)va_arg(*ap, unsigned long long);
	string = ft_base_converter(num, 16);
	if (flag->conversion == HEX_UPPER)
		string = ft_strtoupper(string);
	string = int_string_builder(string, flag);
	ft_putstr(string);
	size = ft_strlen(string);
	free(string);
	return (size);
}
