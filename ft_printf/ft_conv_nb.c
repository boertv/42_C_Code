/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:12:36 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/09 13:39:04 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_lnblen(t_flag *flag, t_nb_attr *nb, int *mlen)
{
	long	temp;

	temp = nb->lnb;
	nb->nblen = 0;
	if (!nb->lnb && flag->pr != -2)
		nb->nblen++;
	while (temp)
	{
		temp /= nb->baselen;
		nb->nblen++;
	}
	*mlen += nb->nblen;
}

static void	ft_unblen(t_flag *flag, t_nb_attr *nb, int *mlen)
{
	unsigned long	temp;

	temp = nb->unb;
	nb->nblen = 0;
	if (!nb->unb && flag->pr != -2)
		nb->nblen++;
	while (temp)
	{
		temp /= nb->baselen;
		nb->nblen++;
	}
	*mlen += nb->nblen;
}

static void	ft_nb_pr(t_flag *flag, t_nb_attr *nb, int *mlen)
{
	if (flag->pr < nb->nblen)
		flag->pr = 0;
	else
		flag->pr -= nb->nblen;
	*mlen += flag->pr;
}

static void	ft_nb_fw(t_flag *flag, t_nb_attr *nb, int *mlen)
{
	if (flag->fw <= nb->nblen + flag->pr)
		flag->fw = 0;
	else
		flag->fw -= nb->nblen + flag->pr;
	if (nb->s && (nb->lnb < 0 || flag->pl || flag->sp))
	{
		flag->fw += (flag->fw == 0);
		if (nb->lnb < 0)
			nb->sign = '-';
		else if (flag->pl)
			nb->sign = '+';
		else if (flag->sp)
			nb->sign = ' ';
	}
	else
		nb->sign = 0;
	*mlen += flag->fw;
}

char	*ft_conv_nb(t_flag *flag, t_nb_attr *nb, int *mlen, va_list *pva)
{
	char	*to_print;

	nb->baselen = ft_strlen(nb->base);
	flag->zs *= (flag->pr == 0);
	if (ft_flag_nb(flag, nb))
		return (ft_error_null(NULL, NULL, pva));
	if (nb->s)
	{
		nb->lnb = va_arg(*pva, int);
		ft_lnblen(flag, nb, mlen);
	}
	else
	{
		nb->unb = (unsigned int) va_arg(*pva, int);
		ft_unblen(flag, nb, mlen);
	}
	ft_nb_pr(flag, nb, mlen);
	ft_nb_fw(flag, nb, mlen);
	to_print = ft_calloc(*mlen + 1, 1);
	if (!to_print)
		return (ft_error_null("calloc", "conv_nb", pva));
	ft_fill_nb(to_print, flag, nb, mlen);
	return (to_print);
}
