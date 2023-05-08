/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:16:58 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/08 17:07:49 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fill_flag(char *sform, t_flag *flag, int *mlen)
{
	*mlen = 0;
	while (sform[*mlen] != '%' && sform[*mlen])
		(*mlen)++;
	flag->sform = sform;
	flag->fw = ft_field_width(sform + *mlen);
	flag->pr = ft_precision(sform + *mlen);
	flag->lj = ft_left_just(sform + *mlen);
	if (flag->lj)
		flag->zs = 0;
	else
		flag->zs = ft_zeroes(sform + *mlen);
	flag->pl = ft_plus(sform + *mlen);
	if (flag->pl)
		flag->sp = 0;
	else
		flag->sp = ft_space(sform + *mlen);
	flag->ht = ft_hashtag(sform + *mlen);
}

static char	*ft_conv_iux(char cs, t_flag *flag, int *mlen, va_list *pva)
{
	t_nb_attr	nb;

	if (cs == 'i' || cs == 'd')
	{
		nb.s = 1;
		nb.base = "0123456789";
		return (ft_conv_nb(flag, &nb, mlen, pva));
	}
	// nb.s = 0;
	// if (cs == 'u')
	// {
	// 	nb.base = "0123456789";
	// 	return (ft_conv_nb(flag, &nb, mlen, pva));
	// }
	// if (cs == 'x')
	// {
	// 	nb.base = "0123456789abcdef";
	// 	return (ft_conv_nb(flag, &nb, mlen, pva));
	// }
	// if (cs == 'X')
	// {
	// 	nb.base = "0123456789ABCDEF";
	// 	return (ft_conv_nb(flag, &nb, mlen, pva));
	// }
	return (ft_error_null("bad specifier", "ft_conv_hub", pva));
}

char	*ft_conv_hub(char *sform, int *mlen, va_list *pva)
{
	char	conv_spec;
	t_flag	flag;
	char	*to_print;

	if (!ft_strrchr(sform, '%'))
	{
		to_print = ft_strdup(sform);
		if (!to_print)
			return (ft_error_null("strdup", "conv_hub", pva));
		*mlen = ft_strlen(sform);
		return (to_print);
	}
	ft_fill_flag(sform, &flag, mlen);
	if (ft_flag_errors(&flag))
		return (ft_error_null(NULL, NULL, pva));
	conv_spec = sform[ft_strlen(sform) - 1];
	if (conv_spec == 'c')
		return (ft_conv_char(&flag, mlen, pva));
	if (conv_spec == '%')
		return (ft_conv_mod(&flag, mlen, pva));
	if (conv_spec == 's')
		return (ft_conv_str(&flag, mlen, pva));
	// if (conv_spec == 'p')
	// 	return (ft_conv_ptr(&flag, mlen, pva));
	return (ft_conv_iux(conv_spec, &flag, mlen, pva));
}
