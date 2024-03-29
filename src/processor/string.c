/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:54:48 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/24 20:59:03 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	draw_string(struct s_flags *flag, va_list *ap)
{
	char	*string;
	int		size;

	string = va_arg(*ap, char*);
	if (!string)
		string = "(null)";
	string = ft_strdup(string);
	if ((flag->dot) && (!flag->precision))
		string[0] = '\0';
	string = string_builder(string, flag);
	ft_putstr(string);
	size = ft_strlen(string);
	free(string);
	return (size);
}
