/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:16:58 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/05 17:36:39 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fill_flag(t_flag *flag, char *sform)
{
	flag->fw = ft_field_width(sform);
	flag->pr = ft_precision(sform);
	flag->lj = ft_left_just(sform);
	flag->zs = ft_zeroes(sform);
	flag->pl = ft_plus(sform);
	flag->sp = ft_space(sform);
	flag->ht = ft_hashtag(sform);
}

static char	*ft_conv_iux(char *sform, char cs, int *mlen, va_list *pva)
{
	t_nb_attr	nb;

	if (cs == 'i' || cs == 'd')
	{
		nb.s = 1;
		nb.base = "0123456789";
		return (ft_conv_nb(sform, pva, &nb, mlen));
	}
	nb.s = 0;
	if (cs == 'u')
	{
		nb.base = "0123456789";
		return (ft_conv_nb(sform, pva, &nb, mlen));
	}
	if (cs == 'x')
	{
		nb.base = "0123456789abcdef";
		return (ft_conv_nb(sform, pva, &nb, mlen));
	}
	if (cs == 'X')
	{
		nb.base = "0123456789ABCDEF";
		return (ft_conv_nb(sform, pva, &nb, mlen));
	}
	return (ft_error_null("bad specifier", "ft_conv_hub", pva));
}

char	*ft_conv_hub(char *sform, int *mlen, va_list *pva)
{
	char	conv_spec;
	t_flag	flag;
	char	*to_print;

	*mlen = 0;
	flag.sform = sform;
	ft_fill_flag(&flag);
	if (ft_flag_errors(&flag))
		return (ft_error_null(NULL, NULL, pva));
	if (!ft_strrchr(sform, '%'))
	{
		to_print = ft_strdup(sform);
		if (!to_print)
			return (ft_error_null("strdup", "conv_hub", pva));
		return (to_print);
	}
	conv_spec = sform[ft_strlen(sform) - 1];
	if (conv_spec == 'c' || conv_spec == '%')
		return (ft_conv_char(sform, pva, conv_spec, mlen));
	if (conv_spec == 's')
		return (ft_conv_str(sform, pva, mlen));
	if (conv_spec == 'p')
		return (ft_conv_ptr(sform, pva));
	return (ft_conv_iux(sform, conv_spec, mlen, pva));
}
