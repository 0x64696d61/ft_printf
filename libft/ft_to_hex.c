/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:41:17 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/21 14:42:02 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*to_hex(unsigned long long num)
{
	char *string;
	char *p_string;

	p_string = ft_base_converter(num, 16);
	string = ft_strjoin("0x", p_string);
	free(p_string);
	return (string);
}
