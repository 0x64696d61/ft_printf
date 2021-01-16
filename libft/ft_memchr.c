/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:25:50 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 16:13:25 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p_str;

	p_str = (unsigned char *)s;
	while (n)
	{
		if (*p_str == (unsigned char)c)
			return (p_str);
		n--;
		p_str++;
	}
	return (NULL);
}
