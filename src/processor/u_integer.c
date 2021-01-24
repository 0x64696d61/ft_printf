/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_integer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:28:53 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/24 20:58:02 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	draw_u_integer(struct s_flags *flag, va_list *ap)
{
	unsigned int	num;
	char			*string;
	int				size;

	num = va_arg(*ap, unsigned int);
	string = ft_u_itoa(num);
	string = int_string_builder(string, flag);
	ft_putstr(string);
	size = ft_strlen(string);
	free(string);
	return (size);
}
