/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:44:23 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 15:41:29 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *str;

	str = malloc(ft_strlen(s1) + 1);
	if (str == NULL)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}
