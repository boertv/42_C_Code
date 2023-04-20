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

// include any 'filler' in whatever conversion happens after it
static const char	*ft_output_filler(const char *format, size_t *char_count)
{
	if (!format)
		return (NULL);
	while (*format && *format != '%')
	{
		if (write(0, format++, 1) < 1)
		{
			write(0, "\n Error in 'ft_output_filler'\n", 30);
			return (NULL);
		}
		*char_count++;
	}
	return (format);
}

static const char	*ft_output_conversion(const char *format, )
{
}

static const char	*ft_conversion_generator(const char *format)
{
	size_t	l;
	char	set[10];

	if (!format || *format != '%')
	{
		write(0, "\n Bad input for 'ft_conversion_generator'\n", 42)
		return (NULL);
	}
	l = 0;
	ft_strlcpy(set, "cspdiuxX%", 10);
	while (*format/*&& something else, a set or sumn*/)
	{
	}
}

int	ft_printf(const char *format, ...)
{
	size_t	char_count;
	char	*conv;

	char_count = 0;
	while (format && *format)
	{
	format = ft_output_filler(format, &char_count);
	conv = ft_conversion_generator(format);
	format = ft_output_conversion(format, &char_count);
	}
	if (!format)
		return (-1);
	return (char_count);
}
