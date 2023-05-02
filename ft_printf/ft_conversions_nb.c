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

char	*ft_conv_nb(char *sform, va_list *ptr_va, char *base, int sign)
{
	size_t		chars;
	t_nb_attr	sbn;
	char		*to_print;

	sbn.base = base;
	sbn.baselen = ft_strlen(base);
	chars = 0;
	while (sform[chars] && (sform[chars] != '%'))
		chars++;
	if (ft_check_nb(sform + chars, sbn.baselen, sign) == -1)
		return (ft_error_null("flags", "ft_conv_nb", ptr_va));
	if (sign)
		sbn.nb = (long long) va_arg(*ptr_va, int);
	else
		sbn.nb = (long long)((unsigned int) va_arg(*ptr_va, int));
	ft_fill_nbstruct(sform + chars, &sbn, sign);
	if (sbn.pr > 0)
		to_print = ft_calloc(chars + sbn.nblen + sbn.fw + sbn.pr + 1, 1);
	else
		to_print = ft_calloc(chars + sbn.nblen + sbn.fw + 1, 1);
	if (!to_print)
		return (ft_error_null("calloc", "ft_conv_nb", ptr_va));
	ft_strlcpy(to_print, sform, chars + 1);
	ft_fill_nb(to_print + chars, sform + chars, &sbn, sign);
	return (to_print);
}

char	*ft_conv_ptr(char *sform, va_list *ptr_va)
{
	size_t		chars;
	t_nb_attr	snb;
	char		*to_print;

	snb.base = "0123456789abcdef";
	snb.baselen = 16;
	chars = 0;
	while (sform[chars] && (sform[chars] != '%'))
		chars++;
	if (ft_check_char(sform + chars) == -1)
		return (ft_error_null("flags", "ft_conv_ptr", ptr_va));
	snb.nb = (long long)((unsigned long) va_arg(*ptr_va, void *));
	sform[chars] = '#';
	ft_fill_nbstruct(sform + chars, &snb, 0);
	if (snb.pr > 0)
		to_print = ft_calloc(chars + snb.nblen + snb.fw + snb.pr + 1, 1);
	else
		to_print = ft_calloc(chars + snb.nblen + snb.fw + 1, 1);
	if (!to_print)
		return (ft_error_null("calloc", "ft_conv_ptr", ptr_va));
	ft_strlcpy(to_print, sform, chars + 1);
	ft_fill_nb(to_print + chars, sform + chars, &snb, 0);
	return (to_print);
}
