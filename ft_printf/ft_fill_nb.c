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

static int	ft_fieldwidth_nb(char *sub_format, int nblen, int pr)
{
	int	fw;

	fw = ft_field_width(sub_format);
	if (pr < 0)
		pr = 0;
	if (fw <= nblen + pr)
		fw = 0;
	else
		fw -= nblen + pr;
	if (fw < 2 && ft_hashtag(sub_format))
		fw = 2;
	return (fw);
}

static int	ft_precision_nb(char *sub_format, int nblen)
{
	int	pr;

	pr = ft_precision(sub_format);
	if (pr > 0 && pr <= nblen)
		pr = 0;
	else if (pr > 0)
		pr -= nblen;
	return (pr);
}

void	ft_fill_nbstruct(char *sf, t_nb_attr *snb, int sign)
{
	snb->nblen = ft_nblen(sf, snb->nb, snb->baselen, sign);
	snb->pr = ft_precision_nb(sf, snb->nblen);
	snb->fw = ft_fieldwidth_nb(sf, snb->nblen, snb->pr);
}

static void	ft_fill_nb_fw(char *dst, char *sub_format, t_nb_attr *sbn, int h)
{
	if (sbn->pr || !ft_zeroes(sub_format))
	{
		ft_putnchr(dst, ' ', sbn->fw);
		if (h)
		{
			dst[sbn->fw - 2] = '0';
			dst[sbn->fw - 1] = sbn->base[10] + 23;
		}
	}
	else
	{
		ft_putnchr(dst, '0', sbn->fw);
		if (h)
			dst[1] = sbn->base[10] + 23;
	}
}

void	ft_fill_nb(char *dst, char *sub_format, t_nb_attr *sbn, int sign)
{
	int	lj;
	int	h;

	lj = ft_left_just(sub_format);
	h = ft_hashtag(sub_format);
	if (lj)
	{
		if (h)
		{
			*dst++ = '0';
			*dst++ = sbn->base[10] + 23;
			h = 0;
			sbn->fw -= 2;
		}
		ft_putnbr_str(sub_format, dst, sbn, sign);
		while (*dst)
			dst++;
	}
	ft_fill_nb_fw(dst, sub_format, sbn, h);
	if (!lj)
		ft_putnbr_str(sub_format, dst + sbn->fw, sbn, sign);
	return ;
}
