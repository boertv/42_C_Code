/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_ints.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:23:39 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/25 16:24:40 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fieldwidth_int(char *sub_format, int nblen, int pr)
{
	int	fw;

	fw = ft_field_width(sub_format);
	if (pr < 0)
		pr = 0;
	if (fw <= nblen + pr)
		fw = 0;
	else
		fw -= nblen + pr;
	return (fw);
}

static int	ft_precision_int(char *sub_format, int nblen)
{
	int	pr;

	pr = ft_precision(sub_format);
	if (pr > 0 && pr <= nblen)
		pr = 0;
	else if (pr > 0)
		pr -= nblen;
	return (pr);
}

static void	ft_fill_int_print(char *dst, char *sub_format, int nb, t_speclens specl)
{
	int	lj;

	lj = ft_left_just(sub_format);
	if (lj)
	{
		ft_putnbr_str(sub_format, dst, nb, specl.pr);
		while (*dst)
			dst++;
	}
	if (specl.pr || !ft_zeroes(sub_format))
		ft_putnchr(dst, ' ', specl.fw);
	else
		ft_putnchr(dst, '0', specl.fw);
	if (!lj)
		ft_putnbr_str(sub_format, dst + specl.fw, nb, specl.pr);
	return ;
}

	//AAAAAAAAAH
#include <stdio.h>

char	*ft_conversion_int(char *sub_format, va_list *ptr_spec)
{
	size_t	charslen;
	int		nb;
	t_speclens specl;
	char	*to_print;

	charslen = 0;
	while (sub_format[charslen] && (sub_format[charslen] != '%'))
		charslen++;
	if (ft_check_int(sub_format + charslen) == -1)
		return (ft_error_null("flags", "ft_conversion_int", ptr_spec));
	nb = va_arg(*ptr_spec, int);
	specl.nblen = ft_nblen(sub_format, nb);
	specl.pr = ft_precision_int(sub_format + charslen, specl.nblen);
	specl.fw = ft_fieldwidth_int(sub_format + charslen, specl.nblen, specl.pr);
	printf("|-{nblen:%i pr:%i fw:%i}-|", specl.nblen, specl.pr, specl.fw);
	if (specl.pr > 0)
		to_print = ft_calloc(charslen + specl.nblen + specl.fw + specl.pr, sizeof(char));
	else
		to_print = ft_calloc(charslen + specl.nblen + specl.fw, sizeof(char));
	if (!to_print)
		return (ft_error_null("calloc", "ft_conversion_int", ptr_spec));
	ft_strlcpy(to_print, sub_format, charslen + 1);
	ft_fill_int_print(to_print + charslen, sub_format, nb, specl);
	return (to_print);
}
