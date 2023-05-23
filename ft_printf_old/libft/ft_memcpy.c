/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:13:23 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/17 11:20:43 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!n)
		return (dst);
	if (!dst || !src)
		return (NULL);
	d = (char *) dst;
	s = (char *) src;
	while (n-- > 0)
		*(d + n) = *(s + n);
	return (dst);
}
