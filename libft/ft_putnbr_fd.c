/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:25:28 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/10 13:11:47 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_writing(int n, int fd)
{
	char	p;
	int		div;

	div = 1000000000;
	while (!(n / div) && div)
		div /= 10;
	while (div)
	{
		p = n / div + '0';
		if (write(fd, &p, 1) < 0)
			return ;
		n %= div;
		div /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (!n)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		if (write(fd, "-", 1) < 0)
			return ;
		n *= -1;
	}
	ft_writing(n, fd);
}
