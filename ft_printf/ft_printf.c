/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:44:30 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/19 15:20:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// for the minimum field width flag: the function doesn't print anything if
//	it's >= INT_MAX (2147483647) (OR EQUAL TO)
//	(and returns -1 ofc)

// Cuts out a 'sub_format'. Including one specifier and preceding chars.
// Increments the format so we are up to date.
static char	*ft_sub_format(const char **ptr_format, va_list *ptr_spec)
{
	size_t	l;
	char	*sub_format;

	if (!ptr_format || !*ptr_format || !**ptr_format)
		return (ft_error_null("input", "ft_sub_format", ptr_spec));
	l = 0;
	while ((*ptr_format)[l] && (*ptr_format)[l] != '%')
		l++;
	if ((*ptr_format)[l] == '%')
		l++;
	while ((*ptr_format)[l] && !ft_strchr("cspdiuxX%", (*ptr_format)[l]))
		l++;
	if ((*ptr_format)[l] && ft_strchr("cspdiuxX%", (*ptr_format)[l]))
		l++;
	sub_format = ft_substr(*ptr_format, 0, l);
	if (!sub_format)
		return (ft_error_null("ft_substr(malloc?)", "ft_sub_format", ptr_spec));
	*ptr_format += l;
	return (sub_format);
}

// calls a different function depending on the specifier type.
static char	*ft_output_conversion(char *sub_format, va_list *ptr_spec)
{
	char	conv_spec;

	if (!ft_strrchr(sub_format, '%'))
		return (ft_strdup(sub_format));
	conv_spec = sub_format[ft_strlen(sub_format) - 1];
	if (conv_spec == 'c' || conv_spec == '%')
		return (ft_conv_char(sub_format, ptr_spec, conv_spec));
	if (conv_spec == 's')
		return (ft_conv_str(sub_format, ptr_spec));
	if (conv_spec == 'i' || conv_spec == 'd')
		return (ft_conv_nb(sub_format, ptr_spec, "0123456789", 1));
	if (conv_spec == 'u')
		return (ft_conv_nb(sub_format, ptr_spec, "0123456789", 0));
	if (conv_spec == 'x')
		return (ft_conv_nb(sub_format, ptr_spec, "0123456789abcdef", 0));
	if (conv_spec == 'X')
		return (ft_conv_nb(sub_format, ptr_spec, "0123456789ABCDEF", 0));
	if (conv_spec == 'p')
		return (ft_conv_ptr(sub_format, ptr_spec));
	return (ft_error_null("specifier", "ft_output_conversion", ptr_spec));
}

int	ft_printf(const char *format, ...)
{
	size_t	char_count;
	char	*sub_format;
	char	*to_print;
	va_list	specifier;

	if (!format)
		return (-1);
	char_count = 0;
	va_start(specifier, format);
	while (*format)
	{
		sub_format = ft_sub_format(&format, &specifier);
		if (!sub_format)
			return (-1);
		to_print = ft_output_conversion(sub_format, &specifier);
		free(sub_format);
		if (!to_print)
			return (-1);
		char_count += write(0, to_print, ft_strlen(to_print));
		free(to_print);
	}
	va_end(specifier);
	return (char_count);
}
