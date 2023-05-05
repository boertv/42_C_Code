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

static int	ft_precision_str(char *sform, char *str)
{
	int	pr;
	int	len;

	pr = ft_precision(sform);
	len = (int) ft_strlen(str);
	if (pr == 0 || pr > len)
		return (len);
	if (pr == -2)
		return (0);
	return (pr);
}

static int	ft_fieldwidth_str(char *sform, int pr)
{
	int	fw;

	fw = ft_field_width(sform);
	if (fw < pr)
		return (pr);
	return (fw);
}

static char	*ft_initialise_str(char *str, va_list *ptr_va, int *ns)
{
	*ns = 0;
	str = va_arg(*ptr_va, char *);
	if (!str)
	{
		str = ft_strdup("(null)");
		*ns = 1;
	}
	return (str);
}

char	*ft_conv_str(char *sform, va_list *ptr_va)
{
	size_t		chars;
	t_str_attr	sstr;
	char		*to_print;
	int			ns;

	chars = 0;
	while (sform[chars] && (sform[chars] != '%'))
		chars++;
	if (ft_check_str(sform + chars) == -1)
		return (ft_error_null("flags", "ft_conv_str", ptr_va));
	sstr.str = ft_initialise_str(sstr.str, ptr_va, &ns);
	sstr.pr = ft_precision_str(sform + chars, sstr.str);
	sstr.fw = ft_fieldwidth_str(sform + chars, sstr.pr);
	to_print = calloc(chars + sstr.fw + 1, sizeof(char));
	if (!to_print)
		return (ft_error_null("calloc", "ft_conv_str", ptr_va));
	ft_strlcpy(to_print, sform, chars + 1);
	ft_fill_str_print(to_print, &sstr, ft_left_just(sform + chars));
	if (ns)
		free(sstr.str);
	return (to_print);
}
