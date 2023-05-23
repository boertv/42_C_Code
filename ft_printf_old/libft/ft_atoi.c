/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:19:31 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/17 10:12:24 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(short sign)
{
	if (sign > 0)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	long long	n;
	short		sign;

	if (!str)
		return (0);
	n = 0;
	sign = -1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 - (*str - '0');
		str++;
		if (n > 0)
			return (ft_overflow(sign));
	}
	return (sign * n);
}
