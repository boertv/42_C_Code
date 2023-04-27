/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_nb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:23:39 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/25 16:24:40 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fieldwidth_nb(char *sub_format, int nblen, int pr)
{
	int	fw;

	fw = ft_field_width(sub_format);
	if (pr < 0)
		pr = 0;
	if (fw <= nblen + pr)
		fw = 0;
	else
		fw -= nblen + pr;
	if (fw < 2 && ft_hashtag(sub_format))
		fw = 2;
	return (fw);
}

static int	ft_precision_nb(char *sub_format, int nblen)
{
	int	pr;

	pr = ft_precision(sub_format);
	if (pr > 0 && pr <= nblen)
		pr = 0;
	else if (pr > 0)
		pr -= nblen;
	return (pr);
}

static void	ft_fill_nb_print(char *dst, char *sub_format, t_nb_attr *nb_attr)
{
	int	lj;
	int	h;

	lj = ft_left_just(sub_format);
	h = ft_hashtag(sub_format);
	if (lj)
	{
		ft_putnbr_str(sub_format, dst, nb_attr);
		while (*dst)
			dst++;
	}
	if (nb_attr->pr || !ft_zeroes(sub_format))
		ft_putnchr(dst, ' ', nb_attr->fw);
		if (h)
		{
			dst[nb_attr->fw - 2] = '0';
			dst[nb_attr->fw - 1] = nb_attr->base[10] + 23;
		}
	else
		ft_putnchr(dst, '0', nb_attr->fw);
		if (h)
			dst[1] = nb_attr->base[10] + 23;
	if (!lj)
		ft_putnbr_str(sub_format, dst + nb_attr->fw, nb_attr);
	return ;
}

static void	ft_fill_nbstruct(char *sf, t_nb_attr *na, va_list *ps, int sign)
{
	if (sign)
		na->nb = (long) va_arg(*ps, int);
	else
		na->nb = (long) ((unsigned int) va_arg(*ps, int));
	na->nblen = ft_nblen(sf, na->nb, na->baselen);
	na->pr = ft_precision_nb(sf, na->nblen);
	na->fw = ft_fieldwidth_nb(sf, na->nblen, na->pr);
}

char	*ft_conv_nb(char *sub_format, va_list *ptr_spec, char *base, int sign)
{
	size_t		charslen;
	t_nb_attr	nb_attr;
	char		*to_print;

	nb_attr.base = base;
	nb_attr.baselen = ft_strlen(base);
	charslen = 0;
	while (sub_format[charslen] && (sub_format[charslen] != '%'))
		charslen++;
	if (ft_check_nb(sub_format + charslen, nb_attr.baselen, sign) == -1)
		return (ft_error_null("flags", "ft_check_nb", ptr_spec));
	ft_fill_nbstruct(sub_format + charslen, &nb_attr, ptr_spec, sign);
	if (nb_attr.pr > 0)
		to_print = ft_calloc(charslen + nb_attr.nblen + nb_attr.fw + nb_attr.pr + 1, sizeof(char));
	else
		to_print = ft_calloc(charslen + nb_attr.nblen + nb_attr.fw + 1, sizeof(char));
	if (!to_print)
		return (ft_error_null("calloc", "ft_conv_nb", ptr_spec));
	ft_strlcpy(to_print, sub_format, charslen + 1);
	ft_fill_nb_print(to_print + charslen, sub_format + charslen, &nb_attr);
	return (to_print);
}
