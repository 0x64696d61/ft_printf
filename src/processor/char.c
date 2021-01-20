/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:26:46 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/20 18:55:38 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void processing_nonprintable(char *string, struct s_flags *flag)
{
	char	*str;
	int		offset;

	if (flag->width)
	{
		if ((offset = flag->width - 1) > 0)
		{
			str = malloc(sizeof(char*) * offset + 1);
			str[offset] = '\0';
			ft_memset(str, flag->zero, offset);
			if (flag->minus)
			{
				ft_putchar(*string);
				ft_putstr(str);
			}
			else
			{
				ft_putstr(str);
				ft_putchar(*string);
			}
			free(str);
		}
	}
	else
		ft_putchar(*string);

}

void	draw_char(struct s_flags *flag, va_list *ap)
{
	char *string;

	string = malloc(sizeof(char) * 1 + 1);
	string[0] = (char)va_arg(*ap, int);
	string[1] = '\0';

	if (ft_strlen(string) == 0)
		processing_nonprintable(string, flag);
	else
	{
		string = string_builder(string, flag);
		ft_putstr(string);
	}
	free(string);
}
