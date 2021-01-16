/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:50:19 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/20 16:04:12 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num[11];
	long	nbr;
	int		i;

	nbr = n;
	i = 0;
	if (nbr == 0)
		write(fd, "0", 1);
	if (!n || !fd)
		return ;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		write(fd, "-", 1);
	}
	while (nbr > 0)
	{
		num[i] = '0' + nbr % 10;
		nbr = nbr / 10;
		i++;
	}
	while (i-- > 0)
	{
		write(fd, &num[i], 1);
	}
}
