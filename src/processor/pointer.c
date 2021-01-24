/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:39:04 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/24 20:39:52 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	draw_pointer(struct s_flags *flag, va_list *ap)
{
	unsigned long long	num;
	char				*string;
	int					size;

	num = va_arg(*ap, unsigned long long);
	if (!num)
	{
		num = 0;
		if (flag->dot && flag->precision == 0)
			flag->precision = 2;
	}
	string = string_builder(to_hex(num), flag);
	ft_putstr(string);
	size = ft_strlen(string);
	free(string);
	return (size);
}
