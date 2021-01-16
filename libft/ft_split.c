/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:58:58 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 17:51:45 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	worlds_counter(char *s, char c)
{
	int		words;
	int		pr;

	words = 0;
	pr = 0;
	while (*s != '\0')
	{
		if (pr == 0 && *s != c)
		{
			words++;
			pr = 1;
		}
		if (*s == c)
			pr = 0;
		s++;
	}
	return (words);
}

size_t	characters(char const *s, char c, size_t position)
{
	size_t counter;

	counter = 0;
	while (s[position - 1 - counter] != c && position - 1 - counter > 0)
		counter++;
	if (position - counter == 1 && s[0] != c)
		counter++;
	return (counter);
}

size_t	seperator(char const *s, char c, size_t position)
{
	int i;

	i = 0;
	while (s[position - 1 - i] == c)
		i++;
	return (i);
}

void	free_mem(char **result, int size)
{
	while (result[size--])
		free(result[size]);
}

char	**ft_split(char const *s, char c)
{
	size_t	worlds;
	size_t	size;
	char	**result;
	size_t	position;

	if (!(s))
		return (0);
	worlds = worlds_counter((char*)s, c);
	if (!(result = malloc(sizeof(char**) * (worlds + 1))))
		return (0);
	result[worlds] = NULL;
	position = ft_strlen(s);
	while (worlds--)
	{
		position = position - seperator(s, c, position);
		size = characters(s, c, position);
		position = position - size;
		if (!(result[worlds] = ft_substr(s, position, size)))
		{
			free_mem(result, worlds);
			free(result);
			return (0);
		}
	}
	return (result);
}
