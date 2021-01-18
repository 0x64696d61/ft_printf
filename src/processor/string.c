/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:54:48 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/18 22:01:08 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*string_builder(char *string, struct s_flags *flag)
{
	int		offset;
	char	*str;
	char	*str1;

	if (flag->precision)
		if (((int)ft_strlen(string) > flag->precision))
			string[flag->precision] = '\0';
	if ((flag->dot) && (!flag->precision))
		string[0] = '\0';
	if (flag->width)
		if ((offset = flag->width - (int)ft_strlen(string)) > 0)
		{
			str = malloc(sizeof(char*) * offset + 1);
			str[offset] = '\0';
			ft_memset(str, flag->zero, offset);
			if (flag->minus)
				str1 = ft_strjoin(string, str);
			else
				str1 = ft_strjoin(str, string);
			free(str);
			free(string);
			return (str1);
		}
	return (string);
}

void	draw_string(struct s_flags *flag, va_list *ap)
{
	char *string;

	string = va_arg(*ap, char*);
	if (!string)
		string = "(null)";
	string = ft_strdup(string);
	string = string_builder(string, flag);
	ft_putstr(string);
	free(string);
}
