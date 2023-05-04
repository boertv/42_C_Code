/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:32:34 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/04 11:32:36 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*ft_fill_nb_lj(char *dst, char *sform, t_nb_attr *snb, int h)
{
	if (h)
	{
		*dst++ = '0';
		*dst++ = snb->base[10] + 23;
		snb->fw -= 2;
	}
	ft_write_sign(sform, dst, snb->lnb, snb->sign);
	ft_putnbr_str(dst, snb);
	while (*dst)
		dst++;
	return (dst);
}

void	ft_fill_nb(char *dst, char *sform, t_nb_attr *snb, int ptr_ind)
{
	int	lj;
	int	h;
	int	s;

	lj = ft_left_just(sform);
	h = ft_hashtag(sform);
	if (!ptr_ind && ((snb->sign && !snb->lnb) || (!snb->sign && !snb->unb)))
		h = 0;
	s = 0;
	if (lj)
	{
		dst = ft_fill_nb_lj(dst, sform, snb, h);
		h = 0;
		s = 1;
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
