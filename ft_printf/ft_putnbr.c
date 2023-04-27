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

int	ft_nblen(char *sub_format, int nb, int baselen, int sign)
{
	int	l;

	l = 0;
	if (ft_plus(sub_format) || ft_space(sub_format) || (nb < 0 && sign)
		|| (!nb && ft_precision(sub_format) != -2))
		l++;
	while (nb)
	{
		nb /= baselen;
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

	//AAAAAAAAAAAh
	//#include <stdio.h>

static void	ft_writing(char *dst, t_nb_attr *nb_attr, int local_pr)
{
	int	i;

	i = nb_attr->nblen + local_pr - 1;
	///**/	printf("\nnb = %li  baselen = %i  base = %s\n", nb_attr->nb, nb_attr->baselen, nb_attr->base);
	if (nb_attr->nb < 0)
	{
		dst[i] = nb_attr->base[-(nb_attr->nb % nb_attr->baselen)];
		nb_attr->nb /= -nb_attr->baselen;
		i--;
	}
	while (nb_attr->nb)
	{
		dst[i] = nb_attr->base[(nb_attr->nb % nb_attr->baselen)];
		nb_attr->nb /= nb_attr->baselen;
		i--;
	}
	return ;
}

void	ft_putnbr_str(char *sub_format, char *dst, t_nb_attr *nb_attr, int sign)
{
	int	local_pr;

	if (!nb_attr->nblen)
		return ;
	local_pr = nb_attr->pr;
	if (sign)
		ft_write_sign(sub_format, dst, nb_attr->nb);
	if (!nb_attr->nb)
		local_pr++;
	if (*dst)
		ft_putnchr(dst + 1, '0', local_pr);
	else
		ft_putnchr(dst, '0', local_pr);
	ft_writing(dst, nb_attr, local_pr);
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
