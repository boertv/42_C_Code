/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:46:37 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/24 14:46:39 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// no errors possible in most of these functions
int	ft_zeroes(char *sform)
{
	int	i;

	i = 0;
	while (sform[i])
	{
		if (sform[i] == '0' && (!i
				|| sform[i - 1] <= '0' || sform[i - 1] >= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_hashtag(char *sform)
{
	while (*sform)
	{
		if (*sform == '#')
			return (1);
		sform++;
	}
	return (0);
}

int	ft_plus(char *sform)
{
	while (*sform)
	{
		if (*sform == '+')
			return (1);
		sform++;
	}
	return (0);
}

// -1 on error: if '+' is present
int	ft_space(char *sform)
{
	int	p;

	p = ft_plus(sform);
	while (*sform)
	{
		if (*sform == ' ')
		{
			if (p)
				return (-1);
			return (1);
		}
		sform++;
	}
	return (0);
}
