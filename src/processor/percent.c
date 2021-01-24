/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:13:18 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/24 20:58:41 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	draw_percent(struct s_flags *flag)
{
	char	*string;
	int		size;

	string = ft_strdup("%");
	if ((flag->dot) && (!flag->precision))
		string[0] = '%';
	if (flag->dot == 1 && (!flag->precision) && flag->width <= 0)
	{
		flag->zero = ' ';
	}
	string = string_builder(string, flag);
	ft_putstr(string);
	size = ft_strlen(string);
	free(string);
	return (size);
}
