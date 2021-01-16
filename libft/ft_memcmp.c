/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:08:01 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 16:11:46 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *ps1;
	const unsigned char *ps2;

	ps1 = s1;
	ps2 = s2;
	while (n)
	{
		if (*ps1 != *ps2)
		{
			return ((int)*ps1 - *ps2);
		}
		n--;
		ps1++;
		ps2++;
	}
	return (0);
}
