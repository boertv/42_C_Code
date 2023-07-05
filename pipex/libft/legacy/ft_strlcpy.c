/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:44:07 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/12 14:30:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;

	n = 0;
	if (!src)
		return (0);
	while (*(src + n))
		n++;
	if (!dst || !dstsize)
		return (n);
	if (dstsize <= n)
		*(dst + --dstsize) = 0;
	else
		dstsize = n + 1;
	while (dstsize-- > 0)
		*(dst + dstsize) = *(src + dstsize);
	return (n);
}
