/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 22:44:20 by pstrait           #+#    #+#             */
/*   Updated: 2021/01/24 22:44:22 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
