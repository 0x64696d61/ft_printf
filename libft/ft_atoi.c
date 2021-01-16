/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:59:42 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 19:50:56 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INT_MAX 2147483647

char	*skip_not_valid_chars(char *str)
{
	while ((*str == '\t' || *str == '\v' || *str == '\f' || *str == '\r'
		|| *str == '\n' || *str == ' ') && (*str != '-') && (*str != '+'))
		str++;
	if (*str == '+' && *(str + 1) != '-')
		str++;
	return (str);
}

int		ft_atoi(const char *str)
{
	long long	result;
	int			flag;

	flag = 1;
	result = 0;
	str = (skip_not_valid_chars((char*)str));
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result != 0)
		{
			if ((result * flag * 10 < INT_MAX * flag - 1) && (flag == -1))
				return (0);
			if (result * 10 > INT_MAX)
				return (-1);
			result = result * 10;
		}
		result += *str - '0';
		str++;
	}
	return ((int)result * flag);
}
