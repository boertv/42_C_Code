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

int	ft_nblen(char *sub_format, int nb)
{
	int	l;

	l = 0;
	if (ft_plus(sub_format) || ft_space(sub_format) || nb < 0
		|| (!nb && ft_precision(sub_format) != -2))
		l++;
	while (nb)
	{
		nb /= 10;
		l++;
	}
	return (l);
}

static void	ft_write_sign(char *sub_format, char *dst, int nb)
{
	if (nb < 0)
		*dst = '-';
	else if (ft_space(sub_format))
		*dst = ' ';
	else if (ft_plus(sub_format))
		*dst = '+';
}

static void	ft_writing(char *dst, int nb, int l)
{
	if (nb < 0)
	{
		dst[l] = -(nb % 10) + '0';
		nb /= -10;
		l--;
	}
	while (nb)
	{
		dst[l] = (nb % 10) + '0';
		nb /= 10;
		l--;
	}
	return ;
}

void	ft_putnbr_str(char *sub_format, char *dst, int nb, int pr)
{
	int	l;

	l = ft_nblen(sub_format, nb);
	if (!l)
		return ;
	ft_write_sign(sub_format, dst, nb);
	if (!nb)
		pr++;
	if (*dst)
		ft_putnchr(dst + 1, '0', pr);
	else
		ft_putnchr(dst, '0', pr);
	ft_writing(dst, nb, l + pr - 1);
	return ;
}

void	ft_putnchr(char *dst, char c, int n)
{
	if (n <= 0)
		return ;
	while (n--)
		dst[n] = c;
	return ;
}
