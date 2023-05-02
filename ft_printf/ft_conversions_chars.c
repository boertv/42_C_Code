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

char	*ft_conv_char(char *sform, va_list *ptr_va, char c, size_t *printlen)
{
	size_t	chars;
	int		fw;
	char	*to_print;

	chars = 0;
	while (sform[chars] && (sform[chars] != '%'))
		chars++;
	if (ft_check_char(sform + chars) == -1)
		return (ft_error_null("flags", "ft_conv_char", ptr_va));
	fw = ft_field_width((sform + chars));
	if (!fw)
		fw = 1;
	*printlen = chars + fw;
	to_print = calloc(*printlen + 1, sizeof(char));
	if (!to_print)
		return (ft_error_null("calloc", "ft_conv_char", ptr_va));
	ft_strlcpy(to_print, sform, chars + 1);
	if (c == 'c')
		c = (char) va_arg(*ptr_va, int);
	ft_fill_char_print(to_print, c,
		fw, ft_left_just(sform + chars));
	return (to_print);
}

static int	ft_fieldwidth_str(char *sform, char *str)
{
	size_t	fw;
	size_t	len;

	fw = (size_t) ft_field_width(sform);
	len = ft_strlen(str);
	if (fw < len)
		fw = len;
	return (fw);
}

static void	ft_fill_str_print(char *dst, const char *str, int fw, int lj)
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

char	*ft_conv_str(char *sform, va_list *ptr_va)
{
	size_t	chars;
	int		fw;
	char	*to_print;
	char	*str;

	chars = 0;
	while (sform[chars] && (sform[chars] != '%'))
		chars++;
	if (ft_check_char(sform + chars) == -1)
		return (ft_error_null("flags", "ft_conv_str", ptr_va));
	str = va_arg(*ptr_va, char *);
	if (str)
		fw = ft_fieldwidth_str((sform + chars), str);
	else
		fw = ft_fieldwidth_str((sform + chars), "(null)");
	to_print = calloc(chars + fw + 1, sizeof(char));
	if (!to_print)
		return (ft_error_null("calloc", "ft_conv_str", ptr_va));
	ft_strlcpy(to_print, sform, chars + 1);
	if (str)
		ft_fill_str_print(to_print, str, fw, ft_left_just(sform + chars));
	else
		ft_fill_str_print(to_print, "(null)", fw, ft_left_just(sform + chars));
	return (to_print);
}
