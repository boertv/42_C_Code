/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_chars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:08:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/24 13:08:57 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fill_char_print(char *dst, char c, int fw, int lj)
{
	while (*dst)
		dst++;
	if (lj)
	{
		*dst = c;
		dst++;
	}
	while (--fw)
	{
		*dst = ' ';
		dst++;
	}
	if (!lj)
		*dst = c;
	return ;
}

char	*ft_conv_char(char *sub_format, va_list *ptr_spec, char c)
{
	size_t	len;
	int		field_width;
	char	*to_print;

	len = 0;
	while (sub_format[len] && (sub_format[len] != '%'))
		len++;
	if (ft_check_char(sub_format + len) == -1)
		return (ft_error_null("flags", "ft_conv_char", ptr_spec));
	field_width = ft_field_width((sub_format + len));
	if (!field_width)
		field_width = 1;
	len += field_width;
	to_print = calloc(len + 1, sizeof(char));
	if (!to_print)
		return (ft_error_null("calloc", "ft_conv_char", ptr_spec));
	ft_strlcpy(to_print, sub_format, len - field_width + 1);
	if (c == 'c')
		c = (char) va_arg(*ptr_spec, int);
	ft_fill_char_print(to_print, c,
		field_width, ft_left_just(sub_format + len - field_width));
	return (to_print);
}

static int	ft_fieldwidth_str(char *sub_format, char *str)
{
	size_t	fw;
	size_t	len;

	fw = (size_t) ft_field_width(sub_format);
	len = ft_strlen(str);
	if (fw < len)
		fw = len;
	return (fw);
}

static void	ft_fill_str_print(char *dst, char *str, int fw, int lj)
{
	int	len;

	len = ft_strlen(str);
	fw -= len;
	while (*dst)
		dst++;
	if (lj)
	{
		ft_strlcat(dst, str, len + 1);
		dst += len;
	}
	while (fw-- > 0)
	{
		*dst = ' ';
		dst++;
	}
	if (!lj)
		ft_strlcat(dst, str, len + 1);
}

char	*ft_conv_str(char *sub_format, va_list *ptr_spec)
{
	size_t	len;
	int		field_width;
	char	*to_print;
	char	*str;

	len = 0;
	while (sub_format[len] && (sub_format[len] != '%'))
		len++;
	if (ft_check_char(sub_format + len) == -1)
		return (ft_error_null("flags", "ft_conv_str", ptr_spec));
	str = va_arg(*ptr_spec, char *);
	field_width = ft_fieldwidth_str((sub_format + len), str);
	len += field_width;
	to_print = calloc(len + 1, sizeof(char));
	if (!to_print)
		return (ft_error_null("calloc", "ft_conv_str", ptr_spec));
	ft_strlcpy(to_print, sub_format, len - field_width + 1);
	ft_fill_str_print(to_print, str,
		field_width, ft_left_just(sub_format + len - field_width));
	return (to_print);
}
