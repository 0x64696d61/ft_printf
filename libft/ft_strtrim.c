/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:20:19 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 20:02:50 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		char_exist(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (0);
		}
		set++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		max_str1;
	char	*str1;
	char	*pset;
	char	*new_string;

	str1 = (char *)s1;
	pset = (char *)set;
	if (!s1 || !set)
		return (NULL);
	while (*str1)
	{
		if (char_exist(*str1, pset) != 0)
			break ;
		str1++;
	}
	max_str1 = ft_strlen(str1);
	while (max_str1 > 0)
	{
		if (char_exist(str1[max_str1 - 1], pset) != 0)
			break ;
		max_str1--;
	}
	new_string = malloc(max_str1 + 1);
	ft_strlcpy(new_string, str1, max_str1 + 1);
	return (new_string);
}
