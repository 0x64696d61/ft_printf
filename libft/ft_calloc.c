/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:24:29 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 16:55:43 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	mem_size;
	char	*mem;

	mem_size = count * size;
	mem = malloc(mem_size);
	if (mem)
	{
		ft_bzero(mem, mem_size);
		return (mem);
	}
	else
		return (NULL);
}
