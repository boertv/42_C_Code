/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:58:51 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/03 11:59:04 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lnblen(char *sform, long nb, int baselen)
{
	int	l;

	l = 0;
	if (ft_plus(sform) || ft_space(sform) || nb < 0)
		l++;
	if (!nb && ft_precision(sform) != -2)
		l++;
	while (nb)
	{
		nb /= baselen;
		l++;
	}
	return (l);
}

int	ft_unblen(char *sform, unsigned long nb, int baselen)
{
	int	l;

	l = 0;
	if (!nb && ft_precision(sform) != -2)
		l++;
	while (nb)
	{
		nb /= baselen;
		l++;
	}
	return (l);
}
