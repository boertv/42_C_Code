/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:23:09 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/06 12:59:09 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	if (!n || !s1 || !s2)
		return (0);
	st1 = (unsigned char *) s1;
	st2 = (unsigned char *) s2;
	i = 0;
	while (i++ < n)
		if (*(st1 + i - 1) != *(st2 + i - 1))
			return (*(st1 + i - 1) - *(st2 + i - 1));
	return (0);
}
