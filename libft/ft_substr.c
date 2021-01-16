/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:17:02 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 13:21:02 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s)
		return (NULL);
	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (start <= ft_strlen(s))
		ft_strlcpy(str, s + start, len + 1);
	else
		*str = 0;
	return (str);
}
