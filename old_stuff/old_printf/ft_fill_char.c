/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:48:43 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/02 14:48:45 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_char_print(char *dst, char c, int fw, int lj)
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

void	ft_fill_str_print(char *dst, t_str_attr *sstr, int lj)
{
	sstr->fw -= sstr->pr;
	while (*dst)
		dst++;
	if (lj)
	{
		ft_strlcat(dst, sstr->str, sstr->pr + 1);
		dst += sstr->pr;
	}
	while (sstr->fw-- > 0)
	{
		*dst = ' ';
		dst++;
	}
	if (!lj)
		ft_strlcat(dst, sstr->str, sstr->pr + 1);
}
