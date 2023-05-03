/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_nb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:23:39 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/25 16:24:40 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fieldwidth_nb(char *sform, int nblen, int pr)
{
	int	fw;

	fw = ft_field_width(sform);
	if (pr < 0)
		pr = 0;
	if (fw <= nblen + pr)
		fw = 0;
	else
		fw -= nblen + pr;
	if (fw < 2 && ft_hashtag(sform))
		fw = 2;
	return (fw);
}

static int	ft_precision_nb(char *sform, t_nb_attr *snb, int sign)
{
	int	pr;

	pr = ft_precision(sform);
	if (pr > 0 && pr < snb->nblen)
		return (0);
	if (pr > 0)
	{
		if ((sign && snb->lnb < 0) || ft_plus(sform) || ft_space(sform))
			return (pr - snb->nblen + 1);
		else
			return (pr - snb->nblen);
	}
	return (pr);
}

void	ft_fill_nbstruct(char *sf, t_nb_attr *snb, int sign)
{
	if (sign)
		snb->nblen = ft_lnblen(sf, snb->lnb, snb->baselen);
	else
		snb->nblen = ft_unblen(sf, snb->unb, snb->baselen);
	snb->sign = sign;
	snb->pr = ft_precision_nb(sf, snb, sign);
	snb->fw = ft_fieldwidth_nb(sf, snb->nblen, snb->pr);
}

static int	ft_fill_nb_fw(char *dst, char *sform, t_nb_attr *snb, int h)
{
	if (ft_precision(sform) || !ft_zeroes(sform))
	{
		ft_putnchr(dst, ' ', snb->fw);
		if (h)
		{
			dst[snb->fw - 2] = '0';
			dst[snb->fw - 1] = snb->base[10] + 23;
		}
		return (0);
	}
	else
	{
		ft_write_sign(sform, dst, snb->lnb, snb->sign);
		if (*dst)
			dst++;
		ft_putnchr(dst, '0', snb->fw);
		if (h)
			dst[1] = snb->base[10] + 23;
		return (1);
	}
}

void	ft_fill_nb(char *dst, char *sform, t_nb_attr *snb)
{
	int	lj;
	int	h;
	int	s;

	lj = ft_left_just(sform);
	h = ft_hashtag(sform);
	s = 0;
	if (lj)
	{
		if (h)
		{
			*dst++ = '0';
			*dst++ = snb->base[10] + 23;
			h = 0;
			snb->fw -= 2;
		}
		ft_write_sign(sform, dst, snb->lnb, snb->sign);
		s = 1;
		ft_putnbr_str(dst, snb);
		while (*dst)
			dst++;
	}
	if (ft_fill_nb_fw(dst, sform, snb, h))
		s = 1;
	if (!lj)
	{
		if (!s)
			ft_write_sign(sform, dst + snb->fw, snb->lnb, snb->sign);
		ft_putnbr_str(dst + snb->fw, snb);
	}
	return ;
}
