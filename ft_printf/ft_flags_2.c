/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:14:47 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/05 17:11:10 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// returns 0 for no flag, else returns 1
short	ft_zeroes(char *sform)
{
	int	i;

	i = 0;
	while (sform[i])
	{
		if (sform[i] == '0' && (!i || ((sform[i - 1] < '0'
						|| sform[i - 1] > '9') && sform[i - 1] != '.')))
			return (1);
		i++;
	}
	return (0);
}

// returns 0 for no flag, else returns 1
short	ft_hashtag(char *sform)
{
	while (*sform)
	{
		if (*sform == '#')
			return (1);
		sform++;
	}
	return (0);
}

// returns 0 for no flag, else returns 1
short	ft_plus(char *sform)
{
	while (*sform)
	{
		if (*sform == '+')
			return (1);
		sform++;
	}
	return (0);
}

// returns 0 for no flag, else returns 1
short	ft_space(char *sform)
{
	while (*sform)
	{
		if (*sform == ' ')
			return (1);
		sform++;
	}
	return (0);
}
