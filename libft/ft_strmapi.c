/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:52:13 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 15:19:30 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	buf_size;
	char	*st;
	int		i;

	if (!s || !f)
		return (NULL);
	buf_size = ft_strlen(s);
	st = malloc(buf_size + 1);
	if (st == NULL)
		return (NULL);
	st[buf_size] = '\0';
	i = 0;
	while (*s)
	{
		st[i] = f(i, *s);
		i++;
		s++;
	}
	return (st);
}
