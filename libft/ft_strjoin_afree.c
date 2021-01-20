/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_afree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:42:04 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/20 15:51:41 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_afree(char *s1, char *s2)
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
	printf("s1:%s\n", s1);
	printf("s2:%s\n", s2);
	free(s1);
	free(s2);
	return (str);
}
