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

// for the minimum field width flag: the function doesn't print anything if it's >= INT_MAX (2147483647) (OR EQUAL TO)
//	(and returns -1 ofc)

// Cuts a string out of the format. Including one specifier and preceding loose chars.
// Increments the format so we are up to date.
// ... I think ...
static const char	*ft_sub_format(const char **ptr_format)
{
	size_t	l;
	char	set[10];
	char	*sub_format;

	if (!ptr_format || !*ptr_format)
		return (ft_error_null("input", "ft_sub_format"));
	l = 0;
	ft_strlcpy(set, "cspdiuxX%", 10);
	while (*ptr_format[l] && **ptr_format != '%')
		l++;
	if (*ptr_format[l] == '%')
		l++;
	while (*ptr_format[l] && !ft_strchr(set, *ptr_format[l]))
		l++;
	if (*ptr_format[l] && ft_strchr(set, *ptr_format[l]))
		l++;
	sub_format = (char *) malloc(l + 1);
	if (!sub_format)
		return (ft_error_null("malloc", "ft_sub_format"));
	ft_strlcpy(sub_format, *ptr_format, l + 1);
	*ptr_format += l;
	return (sub_format)
}

static const char	*ft_output_conversion(const char *sub_format)
{
}

int	ft_printf(const char *format, ...)
{
	size_t	char_count;
	char	*sub_format;
	char	*to_print;

	char_count = 0;
	while (format && *format)
	{
	sub_format = ft_sub_format(&format);
	if (!sub_format)
		return (-1);
	to_print = ft_output_conversion(sub_format);
	free(sub_format);
	if (!to_print)
		return (-1);
	char_count += ft_strlen(to_print);
	if (!ft_print_output(to_print))
		format = NULL;
	free(to_print);
	}
	if (!format)
		return (-1);
	return (char_count);
}
