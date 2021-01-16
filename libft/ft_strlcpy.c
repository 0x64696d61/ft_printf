/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:07:35 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 15:25:03 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src,
		size_t dstsize)
{
	size_t			i;
	unsigned char	*psrc;
	unsigned char	*pdst;

	i = 0;
	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (dstsize < 1)
		return (ft_strlen(src));
	if (!dst || !src)
		return ((size_t)NULL);
	while (dstsize - 1 && psrc[i])
	{
		pdst[i] = psrc[i];
		dstsize--;
		i++;
	}
	pdst[i] = '\0';
	return (ft_strlen(src));
}
