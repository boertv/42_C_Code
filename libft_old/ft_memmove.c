/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:19:18 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/17 11:29:46 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!len)
		return (dst);
	if (!dst || !src)
		return (NULL);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (src > dst)
	{
		i = 0;
		while (i++ < len)
			*(d + i - 1) = *(s + i - 1);
	}
	else if (src < dst)
	{
		while (len-- > 0)
			*(d + len) = *(s + len);
	}
	return (dst);
}
