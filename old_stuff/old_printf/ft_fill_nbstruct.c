/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_nbstruct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:30:41 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/04 11:30:51 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_precision_nb(char *sform, t_nb_attr *snb, int sign)
{
	int	pr;

	pr = ft_precision(sform);
	if (pr > 0 && pr < snb->nblen)
		return (0);
	if (pr <= 0)
		return (pr);
	if (((sign && snb->lnb) || (!sign && snb->unb))
		&& ((sign && snb->lnb < 0) || ft_plus(sform) || ft_space(sform)))
		return (pr - snb->nblen + 1);
	else
		return (pr - snb->nblen);
}

static int	ft_fieldwidth_nb(char *sform, int nblen, int pr, int h_ind)
{
	int	fw;

	fw = ft_field_width(sform);
	if (pr < 0)
		pr = 0;
	if (fw <= nblen + pr)
		fw = 0;
	else
		fw -= nblen + pr;
	if (fw < 2 && h_ind && ft_hashtag(sform))
		fw = 2;
	return (fw);
}

void	ft_fill_nbstruct(char *sf, t_nb_attr *snb, int sign, int ptr_ind)
{
	if (sign)
		snb->nblen = ft_lnblen(sf, snb->lnb, snb->baselen);
	else
		snb->nblen = ft_unblen(sf, snb->unb, snb->baselen);
	snb->sign = sign;
	snb->pr = ft_precision_nb(sf, snb, sign);
	if (!ptr_ind && ((sign && !snb->lnb) || (!sign && !snb->unb)))
		snb->fw = ft_fieldwidth_nb(sf, snb->nblen, snb->pr, 0);
	else
		snb->fw = ft_fieldwidth_nb(sf, snb->nblen, snb->pr, 1);
}
