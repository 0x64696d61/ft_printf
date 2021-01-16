/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:51:23 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 15:40:22 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_st;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size_st = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(size_st);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, size_st);
	ft_strlcat(str, s2, size_st);
	return (str);
}
