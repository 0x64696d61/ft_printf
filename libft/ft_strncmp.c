/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:06:44 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 15:15:25 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strncmp -- compare strings
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			size;

	size = n;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (size && *ptr1 && *ptr2)
	{
		if (*ptr1 == *ptr2)
		{
			size--;
			ptr1++;
			ptr2++;
		}
		else
			return (*ptr1 - *ptr2);
	}
	if ((n == ft_strlen(s1) && ptr1[0] == '\0') || size == 0)
		return (0);
	return (*ptr1 - *ptr2);
}
