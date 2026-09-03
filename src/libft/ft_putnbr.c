/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:17:49 by tmachado          #+#    #+#             */
/*   Updated: 2026/09/03 16:59:17 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	c = (nbr % 10) + '0';
	write(fd, &c, 1);
}
