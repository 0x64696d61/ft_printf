/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:08:09 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 16:15:37 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char *s;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n)
	{
		d[i] = s[i];
		if ((unsigned char)c == s[i])
			return (&d[i + 1]);
		i++;
		n--;
	}
	return (NULL);
}
