/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:13:48 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/15 13:57:05 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_str_pr(char *str, t_flag *flag, int *mlen)
{
	int	len;

	len = ft_strlen(str);
	if (!flag->pr || flag->pr > len)
		flag->pr = len;
	else if (flag->pr == -2)
		flag->pr = 0;
	*mlen += flag->pr;
}

static void	ft_str_fw(t_flag *flag, int *mlen)
{
	if (flag->fw <= flag->pr)
		flag->fw = 0;
	else
		flag->fw -= flag->pr;
	*mlen += flag->fw;
}

static void	ft_fill_str(char *to_print, char *str, t_flag *flag, int *mlen)
{
	ft_strlcpy(to_print, flag->sform, *mlen - flag->pr - flag->fw + 1);
	if (flag->lj)
	{
		ft_strlcpy(to_print + *mlen - flag->pr - flag->fw, str, flag->pr + 1);
		ft_putnfw(to_print + *mlen - flag->fw, flag->zs, flag->fw);
	}
	else
	{
		ft_putnfw(to_print + *mlen - flag->pr - flag->fw, flag->zs, flag->fw);
		ft_strlcpy(to_print + *mlen - flag->pr, str, flag->pr + 1);
	}
}

char	*ft_conv_str(t_flag *flag, int *mlen, va_list *pva)
{
	char	*to_print;
	char	*str;

	if (ft_flag_str(flag))
		return (ft_error_null(NULL, "flag_str", NULL));
	str = va_arg(*pva, char *);
	if (!str)
		str = "(null)";
	ft_str_pr(str, flag, mlen);
	ft_str_fw(flag, mlen);
	to_print = ft_calloc(*mlen + 1, 1);
	if (!to_print)
		return (ft_error_null("calloc", "conv_str", NULL));
	ft_fill_str(to_print, str, flag, mlen);
	return (to_print);
}
