/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:14:40 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/05 17:10:49 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_atoi_overflow(char *sform)
{
	int	nb;

	nb = ft_atoi(sform);
	if (nb == -1 || nb == 2147483647)
		return (ft_error_minone("overflow", "fw or pr", NULL));
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
		return (ft_error_minone("invalid conversion specifier", "fw", NULL));
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
		return (ft_error_minone("invalid conversion specifier", "pr", NULL));
	return (pr);
}

// returns 0 for no flag, else returns 1
short	ft_left_just(char *sform)
{
	while (*sform)
	{
		if (*sform == '-')
			return (1);
		sform++;
	}
	return (0);
}
