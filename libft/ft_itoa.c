/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:19:41 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/07 15:54:16 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_rlen(int n)
{
	size_t	l;

	l = 0;
	if (n <= 0)
		l++;
	while (n)
	{
		l++;
		n /= 10;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	size_t	l;
	char	*s;

	l = ft_rlen(n);
	s = (char *) malloc((l + 1) * sizeof(char));
	if (!s)
		return (NULL);
	*(s + l) = 0;
	if (n < 0)
		*s = '-';
	else if (n == 0)
		*s = '0';
	else
		n *= -1;
	while (n)
	{
		l--;
		*(s + l) = -(n % 10) + '0';
		n /= 10;
	}
	return (s);
}
