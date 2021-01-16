/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:07:41 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 19:56:36 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_size;
	size_t src_size;
	size_t total_string_size;
	size_t size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	total_string_size = dstsize;
	if (!dst || !src)
		return ((size_t)NULL);
	if (total_string_size <= dst_size)
		return (total_string_size + src_size);
	dst += dst_size;
	size = total_string_size - dst_size - 1;
	while (size-- && *src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return (dst_size + src_size);
}
