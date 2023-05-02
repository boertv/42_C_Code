/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_nb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:00:07 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/27 16:00:24 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_nb(char *sub_format, va_list *ptr_va, char *base, int sign)
{
	size_t		charslen;
	t_nb_attr	sbn;
	char		*to_print;

	sbn.base = base;
	sbn.baselen = ft_strlen(base);
	charslen = 0;
	while (sub_format[charslen] && (sub_format[charslen] != '%'))
		charslen++;
	if (ft_check_nb(sub_format + charslen, sbn.baselen, sign) == -1)
		return (ft_error_null("flags", "ft_conv_nb", ptr_va));
	if (sign)
		sbn.nb = (long) va_arg(*ptr_va, int);
	else
		sbn.nb = (long)((unsigned int) va_arg(*ptr_va, int));
	ft_fill_nbstruct(sub_format + charslen, &sbn, sign);
	if (sbn.pr > 0)
		to_print = ft_calloc(charslen + sbn.nblen + sbn.fw + sbn.pr + 1, 1);
	else
		to_print = ft_calloc(charslen + sbn.nblen + sbn.fw + 1, 1);
	if (!to_print)
		return (ft_error_null("calloc", "ft_conv_nb", ptr_va));
	ft_strlcpy(to_print, sub_format, charslen + 1);
	ft_fill_nb(to_print + charslen, sub_format + charslen, &sbn, sign);
	return (to_print);
}

char	*ft_conv_ptr(char *sub_format, va_list *ptr_va)
{
	size_t		charslen;
	t_nb_attr	snb;
	char		*to_print;

	snb.base = "0123456789abcdef";
	snb.baselen = 16;
	charslen = 0;
	while (sub_format[charslen] && (sub_format[charslen] != '%'))
		charslen++;
	if (ft_check_char(sub_format + charslen) == -1)
		return (ft_error_null("flags", "ft_conv_ptr", ptr_va));
	snb.nb = (long)((unsigned long) va_arg(*ptr_va, void *));
	sub_format[charslen] = '#';
	ft_fill_nbstruct(sub_format + charslen, &snb, 0);
	if (snb.pr > 0)
		to_print = ft_calloc(charslen + snb.nblen + snb.fw + snb.pr + 1, 1);
	else
		to_print = ft_calloc(charslen + snb.nblen + snb.fw + 1, 1);
	if (!to_print)
		return (ft_error_null("calloc", "ft_conv_ptr", ptr_va));
	ft_strlcpy(to_print, sub_format, charslen + 1);
	ft_fill_nb(to_print + charslen, sub_format + charslen, &snb, 0);
	return (to_print);
}
