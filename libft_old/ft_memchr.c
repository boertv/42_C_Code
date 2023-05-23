/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:37:08 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/06 16:29:40 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*st;
	size_t			i;

	if (!s)
		return (NULL);
	ch = (unsigned char) c;
	st = (unsigned char *) s;
	i = 0;
	while (i++ < n)
		if (*(st + i - 1) == ch)
			return ((st + i - 1));
	return (NULL);
}
