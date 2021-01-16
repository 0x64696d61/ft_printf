/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:07:05 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 15:12:14 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2,
					size_t len)
{
	size_t	size_s2;

	if (*s2 == '\0')
		return ((char*)s1);
	size_s2 = ft_strlen(s2);
	while (len)
	{
		if (ft_strncmp(s1, s2, size_s2) == 0 && len >= size_s2)
			return ((char*)s1);
		s1++;
		len--;
	}
	return (NULL);
}
