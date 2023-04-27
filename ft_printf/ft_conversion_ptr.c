/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:00:07 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/27 16:00:24 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

	//AAAAAAAAAAAAH
	#include<stdio.h>
	//WAAROM NUMMERS TE KORT????
char	*ft_conv_ptr(char *sub_format, va_list *ptr_spec)
{
	size_t		charslen;
	t_nb_attr	nb_attr;
	char		*to_print;

	nb_attr.base = "0123456789abcdef";
	nb_attr.baselen = 16;
	charslen = 0;
	while (sub_format[charslen] && (sub_format[charslen] != '%'))
		charslen++;
	if (ft_check_char(sub_format + charslen) == -1)
		return (ft_error_null("flags", "ft_conv_ptr", ptr_spec));
	nb_attr.nb = (long) ((unsigned int) va_arg(*ptr_spec, void *));
	/**/ printf("\nnb = |%#x| or |%li|\n", (unsigned int) nb_attr.nb, nb_attr.nb);
	ft_fill_nbstruct(sub_format + charslen, &nb_attr, 0);
	if (nb_attr.pr > 0)
		to_print = ft_calloc(charslen + nb_attr.nblen + nb_attr.fw + nb_attr.pr + 1, sizeof(char));
	else
		to_print = ft_calloc(charslen + nb_attr.nblen + nb_attr.fw + 1, sizeof(char));
	if (!to_print)
		return (ft_error_null("calloc", "ft_conv_ptr", ptr_spec));
	ft_strlcpy(to_print, sub_format, charslen + 1);
	sub_format[charslen] = '#';
	ft_fill_nb_print(to_print + charslen, sub_format + charslen, &nb_attr, 0);
	return (to_print);
}
