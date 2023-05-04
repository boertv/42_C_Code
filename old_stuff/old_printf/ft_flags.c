/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:11:57 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/24 12:12:56 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_atoi_overflow(char *sform)
{
	int	nb;

	nb = ft_atoi(sform);
	if (!nb || nb == 2147483647)
		nb = -1;
	return (nb);
}

// returns 0 for no flag, -1 on error
int	ft_field_width(char *sform)
{
	int	fw;

	fw = 0;
	while (*sform)
	{
		if (*sform == '.')
		{
			sform++;
			while (*sform >= '0' && *sform <= '9')
				sform++;
		}
		if (*sform >= '1' && *sform <= '9')
		{
			fw = ft_atoi_overflow(sform);
			while (*sform >= '0' && *sform <= '9')
				sform++;
			break ;
		}
		if (*sform)
			sform++;
	}
	if (fw && (!*sform || !ft_strchr("cspdiuxX%.", *sform)))
		return (-1);
	return (fw);
}

// returns 0 for no flag, -1 on error, -2 for flag of size 0
int	ft_precision(char *sform)
{
	int	pr;

	pr = 0;
	while (*sform)
	{
		if (*sform == '.')
		{
			sform++;
			while (*sform == '0')
				sform++;
			if (*sform >= '1' && *sform <= '9')
			{
				pr = ft_atoi_overflow(sform);
				while (*sform >= '0' && *sform <= '9')
					sform++;
			}
			else
				pr = -2;
			break ;
		}
		sform++;
	}
	if (pr && (!*sform || !ft_strchr("cspdiuxX%", *sform)))
		return (-1);
	return (pr);
}

// returns 0 for no flag, -1 on error
int	ft_left_just(char *sform)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (sform[i])
	{
		if (sform[i] == '-')
		{
			l = 1;
			if (i && (sform[i - 1] == '.'
					|| (sform[i - 1] >= '0' && sform[i - 1] <= '9')))
				return (-1);
			if (ft_zeroes(sform))
				return (-1);
		}
		i++;
	}
	return (l);
}
