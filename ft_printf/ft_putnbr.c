/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:50:29 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/25 16:50:33 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nblen(int n)
{
	int l;

	l = 0;
	if (n <= 0)
		l++;
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static char	*ft_writing(char *dst, int n)
{
	if (n < 0)
	{
		*dst = -(n % 10) + '0';
		n /= -10;
		dst++;
	}
	while (n)
	{
		*dst = (n % 10) + '0';
		n /= 10;
		dst++;
	}
	return (dst);
}

// does it work with INT_MIN?
char	*ft_putnbr_str(int n)
{
	int		l;
	char	*dst;

	l = ft_nblen(n);
	dst = (char) ft_calloc(l + 1, sizeof(char));
	if (!n)
	{
		*dst = '0';
		return (dst);
	}
	if (n < 0)
	{
		*dst = '-';
		ft_writing(dst + 1, n);
	}
	ft_writing(dst, n);
}
