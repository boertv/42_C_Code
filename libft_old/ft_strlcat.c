/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:27:43 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/17 11:34:39 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srcl;
	size_t	dstl;
	size_t	i;

	if (!src)
		return (0);
	srcl = 0;
	dstl = 0;
	while (*(src + srcl))
		srcl++;
	if (!dst || !dstsize)
		return (srcl);
	while (*(dst + dstl))
		dstl++;
	if (dstl > dstsize)
		return (dstsize + srcl);
	i = dstl;
	--dstsize;
	while (i < dstsize && *src)
		*(dst + i++) = *src++;
	*(dst + i) = 0;
	return (srcl + dstl);
}
