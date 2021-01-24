/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:32:22 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/24 22:44:34 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *string)
{
	char *p_string;

	p_string = string;
	while (*p_string)
	{
		*p_string = ft_toupper(*p_string);
		p_string++;
	}
	return (string);
}
