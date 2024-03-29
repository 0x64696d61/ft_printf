/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:29:33 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/26 07:08:56 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_base_converter(unsigned long long num, int notation)
{
	const char	base[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', \
						'a', 'b', 'c', 'd', 'e', 'f' };
	int			mas[64];
	int			i;
	char		*string;
	char		*p_sring;

	i = 0;
	while (num != 0)
	{
		mas[i] = num % notation;
		num = num / notation;
		i++;
	}
	if (i == 0)
	{
		mas[i++] = 0;
	}
	string = malloc(sizeof(char) * i + 1);
	if (string == NULL)
		return (string);
	string[0] = '0';
	string[i] = '\0';
	p_sring = string;
	while (i-- > 0)
		*p_sring++ = base[mas[i]];
	return (string);
}
