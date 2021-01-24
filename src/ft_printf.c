/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:54:48 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/25 00:33:42 by drakosa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	ft_printf(char *line, ...)
{
	struct s_flags	*flag;
	char			**str;
	int				counter;
	int				ret;
	va_list			ap;

	str = &line;
	counter = 0;
	ret = 0;
	va_start(ap, line);
	while (**str != '\0' && ret >= 0)
	{
		flag = init_flags();
		flag = line_parser(str, flag, &counter);
		if (check_flags(flag) == 1)
		{
			if ((ret = run_processor(flag, &ap)) < 0)
				counter = ret;
			counter += ret;
		}
		if (**str != '\0')
			(*str)++;
	}
	va_end(ap);
	return (counter);
}
