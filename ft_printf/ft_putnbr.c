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

int	ft_nblen(char *sub_format, int n)
{
	int	l;

	l = 0;
	if (ft_plus(sub_format) || ft_space(sub_format) || n < 0
		|| (!n && ft_precision(sub_format) != -2))
		l++;
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static void	ft_write_sign(char *sub_format, char *dst, int n)
{
	if (n < 0)
		*dst = '-';
	else if (ft_space(sub_format))
		*dst = ' ';
	else if (ft_plus(sub_format))
		*dst = '+';
}

static void	ft_writing(char *dst, int n, int l)
{
	if (n < 0)
	{
		dst[l] = -(n % 10) + '0';
		n /= -10;
		l--;
	}
	while (n)
	{
		dst[l] = (n % 10) + '0';
		n /= 10;
		l--;
	}
	return ;
}

void	ft_putnbr_str(char *sub_format, char *dst, int n)
{
	int	l;

	l = ft_nblen(sub_format, n);
	if (!l)
		return ;
	ft_write_sign(sub_format, dst, n);
	if (!n)
		*dst = '0';
	else
		ft_writing(dst, n, l - 1);
	return ;
}

void	ft_putnchr(char *dst, char c, int n)
{
	while (n--)
		dst[n] = c;
	return ;
}
