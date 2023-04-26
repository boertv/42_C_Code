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

static int	ft_fieldwidth_int(char *sub_format, int nb, int pr)
{
	int	fw;
	int	nblen;

	nblen = ft_nblen(sub_format, nb);
	fw = ft_field_width(sub_format);
	if (fw <= nblen + pr)
		fw = 0;
	else
		fw -= nblen + pr;
	return (fw);
}

static int	ft_precision_int(char *sub_format, int nb)
{
	int	pr;
	int	nblen;

	nblen = ft_nblen(sub_format, nb);
	pr = ft_precision(sub_format);
	if (pr <= nblen)
		pr = 0;
	else
		pr -= nblen;
	return (pr);
}

char	*ft_conversion_int(char *sub_format, va_list *ptr_spec)
{
	size_t	len;
	int		nb;
	int		field_width;
	int		precision;
	char	*to_print;

	len = 0;
	while (sub_format[len] && (sub_format[len] != '%'))
		len++;
	if (ft_check_int(sub_format + len) == -1)
		return (ft_error_null("flags", "ft_conversion_int", ptr_spec));
	nb = va_arg(*ptr_spec, int);
	precision = ft_precision_int(sub_format + len, nb);
	field_width = ft_fieldwidth_int(sub_format + len, nb, precision);
	// calculate nb length for field_width < nb_len,,, but also precision
}
