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

void	ft_write_sign(char *sform, char *dst, long nb, int sign)
{
	if (!sign)
		return ;
	if (nb < 0)
		*dst = '-';
	else if (ft_space(sform))
		*dst = ' ';
	else if (ft_plus(sform))
		*dst = '+';
}

static void	ft_lwriting(char *dst, t_nb_attr *snb, int local_pr)
{
	int	i;

	i = snb->nblen + local_pr - 1;
	if (snb->lnb < 0)
	{
		dst[i] = snb->base[-(snb->lnb % snb->baselen)];
		snb->lnb /= -snb->baselen;
		i--;
	}
	while (snb->lnb)
	{
		dst[i] = snb->base[(snb->lnb % snb->baselen)];
		snb->lnb /= snb->baselen;
		i--;
	}
	return ;
}

static void	ft_uwriting(char *dst, t_nb_attr *snb, int local_pr)
{
	int	i;

	i = snb->nblen + local_pr - 1;
	while (snb->unb)
	{
		dst[i] = snb->base[(snb->unb % snb->baselen)];
		snb->unb /= snb->baselen;
		i--;
	}
	return ;
}

void	ft_putnbr_str(char *dst, t_nb_attr *snb)
{
	int	local_pr;

	if (!snb->nblen)
		return ;
	local_pr = snb->pr;
	if ((snb->sign && !snb->lnb) || (!snb->sign && !snb->unb))
		local_pr++;
	if (*dst)
		ft_putnchr(dst + 1, '0', local_pr);
	else
		ft_putnchr(dst, '0', local_pr);
	if (local_pr < 0)
		local_pr = 0;
	if (snb->sign)
		ft_lwriting(dst, snb, local_pr);
	else
		ft_uwriting(dst, snb, local_pr);
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
