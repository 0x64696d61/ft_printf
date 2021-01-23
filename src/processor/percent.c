/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:13:18 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/23 18:21:53 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	draw_percent(struct s_flags *flag)
{
	char *string;

	string = "%";
	string = ft_strdup(string);
	if ((flag->dot) && (!flag->precision))
		string[0] = '%';
	string = string_builder(string, flag);
	ft_putstr(string);
	free(string);
	return (ft_strlen(string));
}
