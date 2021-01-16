/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:23:59 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 16:38:36 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	size(long num)
{
	long i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = num * -1;
		i++;
	}
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	num;
	long	i;
	char	*buff;

	num = n;
	i = size(num);
	buff = malloc(i + 1);
	if (buff == NULL)
		return (NULL);
	buff[i] = '\0';
	if (n < 0)
	{
		buff[0] = '-';
		num *= -1;
	}
	if (num == 0 && (buff[0] = 48) == 48)
		return (buff);
	while (num > 0)
	{
		buff[--i] = 48 + (num % 10);
		num = num / 10;
	}
	return (buff);
}
