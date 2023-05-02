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

int	ft_nblen(char *sform, long nb, int baselen, int sign)
{
	int	l;

	l = 0;
	if (ft_plus(sform) || ft_space(sform) || (nb < 0 && sign)
		|| (!nb && ft_precision(sform) != -2))
		l++;
	while (nb)
	{
		nb /= baselen;
		l++;
	}
	return (l);
}

static void	ft_write_sign(char *sform, char *dst, long nb)
{
	if (nb < 0)
		*dst = '-';
	else if (ft_space(sform))
		*dst = ' ';
	else if (ft_plus(sform))
		*dst = '+';
}

static void	ft_writing(char *dst, t_nb_attr *snb, int local_pr)
{
	int	i;

	i = snb->nblen + local_pr - 1;
	if (snb->nb < 0)
	{
		dst[i] = snb->base[-(snb->nb % snb->baselen)];
		snb->nb /= -snb->baselen;
		i--;
	}
	while (snb->nb)
	{
		dst[i] = snb->base[(snb->nb % snb->baselen)];
		snb->nb /= snb->baselen;
		i--;
	}
	return ;
}

void	ft_putnbr_str(char *sform, char *dst, t_nb_attr *snb, int sign)
{
	int	local_pr;

	if (!snb->nblen)
		return ;
	local_pr = snb->pr;
	if (sign)
		ft_write_sign(sform, dst, snb->nb);
	if (!snb->nb)
		local_pr++;
	if (*dst)
		ft_putnchr(dst + 1, '0', local_pr);
	else
		ft_putnchr(dst, '0', local_pr);
	ft_writing(dst, snb, local_pr);
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
