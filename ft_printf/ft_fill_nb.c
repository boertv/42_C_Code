/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:04:22 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/09 13:24:46 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_sign(char *to_print, t_flag *flag, t_nb_attr *nb, int *l)
{
	if (nb->sign)
	{
		*to_print = nb->sign;
		nb->sign = 0;
		flag->fw--;
		++*l;
	}
}

static void	ft_write_nb(char *to_print, t_nb_attr *nb)
{
	int	i;

	i = nb->nblen - 1;
	if (nb->s)
	{
		if (nb->lnb < 0)
		{
			to_print[i--] = nb->base[-(nb->lnb % nb->baselen)];
			nb->lnb /= -nb->baselen;
		}
		while (nb->lnb)
		{
			to_print[i--] = nb->base[(nb->lnb % nb->baselen)];
			nb->lnb /= nb->baselen;
		}
	}
	else
	{
		while (nb->unb)
		{
			to_print[i--] = nb->base[(nb->unb % nb->baselen)];
			nb->unb /= nb->baselen;
		}
	}
}

static void	ft_print_nb(char *to_print, t_flag *flag, t_nb_attr *nb, int *mlen)
{
	if (!nb->nblen)
		return ;
	ft_putnfw(to_print, 1, flag->pr
		+ ((nb->s && !nb->lnb) || (!nb->s && !nb->unb)));
	ft_write_nb(to_print + flag->pr, nb);
	*mlen += flag->pr + nb->nblen;
}

void	ft_fill_nb(char *to_print, t_flag *flag, t_nb_attr *nb, int *mlen)
{
	*mlen -= flag->pr + flag->fw + nb->nblen;
	ft_strlcpy(to_print, flag->sform, *mlen + 1);
	if (flag->lj)
	{
		ft_write_sign(to_print + *mlen, flag, nb, mlen);
		ft_print_nb(to_print + *mlen, flag, nb, mlen);
		ft_putnfw(to_print + *mlen, 0, flag->fw);
	}
	else if (flag->zs)
	{
		ft_write_sign(to_print + *mlen, flag, nb, mlen);
		ft_putnfw(to_print + *mlen, 1, flag->fw);
		ft_print_nb(to_print + *mlen + flag->fw, flag, nb, mlen);
	}
	else
	{
		ft_putnfw(to_print + *mlen, 0, flag->fw);
		ft_write_sign(to_print + *mlen + flag->fw - 1, flag, nb, mlen);
		ft_print_nb(to_print + *mlen + flag->fw, flag, nb, mlen);
	}
	*mlen += flag->fw;
}
