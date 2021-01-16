/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:07:21 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 14:46:40 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strchr -- locate character in string
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	str = str + ft_strlen(s);
	while (*str != c)
	{
		if (str == s)
		{
			return (NULL);
		}
		str--;
	}
	return (str);
}
