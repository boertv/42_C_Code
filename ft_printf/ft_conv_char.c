/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:13:17 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/15 13:57:35 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// appends 'n' spaces or zeroes (depending on 'zs') to 'dst'
void	ft_putnfw(char *dst, short zs, int n)
{
	char	c;

	if (zs)
		c = '0';
	else
		c = ' ';
	if (n <= 0)
		return ;
	while (n--)
		dst[n] = c;
	return ;
}

static void	ft_fill_char(char *to_print, t_flag *flag, int *mlen, char c)
{
	ft_strlcpy(to_print, flag->sform, *mlen + 1);
	if (flag->lj)
		to_print[(*mlen)++] = c;
	ft_putnfw(to_print + *mlen, flag->zs, flag->fw - 1);
	*mlen += flag->fw - 1;
	if (!flag->lj)
		to_print[(*mlen)++] = c;
}

char	*ft_conv_char(t_flag *flag, int *mlen, va_list *pva)
{
	char	*to_print;
	char	c;

	if (ft_flag_char(flag))
		return (NULL);
	if (flag->fw < 1)
		flag->fw = 1;
	to_print = ft_calloc(flag->fw + *mlen + 1, 1);
	if (!to_print)
		return (ft_error_null("calloc", "conv_char", NULL));
	c = (char) va_arg(*pva, int);
	ft_fill_char(to_print, flag, mlen, c);
	return (to_print);
}

char	*ft_conv_mod(t_flag *flag, int *mlen, va_list *pva)
{
	char	*to_print;

	if (flag->fw < 1)
		flag->fw = 1;
	to_print = ft_calloc(flag->fw + *mlen + 1, 1);
	if (!to_print)
		return (ft_error_null("calloc", "conv_mod", NULL));
	ft_fill_char(to_print, flag, mlen, '%');
	return (to_print);
}
