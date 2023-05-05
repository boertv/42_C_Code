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

// Cuts out a 'sub_format'. Including one specifier and preceding chars.
// Increments the format so we are up to date.
static char	*ft_sub_format(const char **ptr_format, va_list *ptr_spec)
{
	size_t	l;
	char	*sform;

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
	sform = ft_substr(*ptr_format, 0, l);
	if (!sform)
		return (ft_error_null("ft_substr(malloc?)", "ft_sub_format", ptr_spec));
	*ptr_format += l;
	return (sform);
}

// calls a different function depending on the specifier type.
static char	*ft_output_conv(char *sform, va_list *ptr_spec, size_t *printlen)
{
	char	conv_spec;

	*printlen = 0;
	if (!ft_strrchr(sform, '%'))
		return (ft_strdup(sform));
	conv_spec = sform[ft_strlen(sform) - 1];
	if (conv_spec == 'c' || conv_spec == '%')
		return (ft_conv_char(sform, ptr_spec, conv_spec, printlen));
	if (conv_spec == 's')
		return (ft_conv_str(sform, ptr_spec));
	if (conv_spec == 'i' || conv_spec == 'd')
		return (ft_conv_nb(sform, ptr_spec, "0123456789", 1));
	if (conv_spec == 'u')
		return (ft_conv_nb(sform, ptr_spec, "0123456789", 0));
	if (conv_spec == 'x')
		return (ft_conv_nb(sform, ptr_spec, "0123456789abcdef", 0));
	if (conv_spec == 'X')
		return (ft_conv_nb(sform, ptr_spec, "0123456789ABCDEF", 0));
	if (conv_spec == 'p')
		return (ft_conv_ptr(sform, ptr_spec));
	return (ft_error_null("specifier", "ft_output_conversion", ptr_spec));
}

static int	ft_printlen(int printlen, char *to_print)
{
	if (!printlen)
		printlen = ft_strlen(to_print);
	return (printlen);
}

int	ft_printf(const char *format, ...)
{
	size_t	char_count;
	char	*sform;
	char	*to_print;
	size_t	printlen;
	va_list	specifier;

	if (!format)
		return (-1);
	char_count = 0;
	va_start(specifier, format);
	while (*format)
	{
		sform = ft_sub_format(&format, &specifier);
		if (!sform)
			return (-1);
		to_print = ft_output_conv(sform, &specifier, &printlen);
		free(sform);
		if (!to_print)
			return (-1);
		printlen = ft_printlen(printlen, to_print);
		char_count += write(1, to_print, printlen);
		free(to_print);
	}
	va_end(specifier);
	return (char_count);
}
