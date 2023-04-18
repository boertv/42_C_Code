/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:31:07 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/17 11:42:40 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// If len == 0 we need to return NULL in all cases where either 
// 	haystack and/or needle are NULL.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;

	if (!haystack || !needle)
		return (NULL);
	l = 0;
	while (*(haystack + l) && l < len)
	{
		i = 0;
		if (*(haystack + l) == *needle)
		{
			while (*(needle + i) && l + i < len)
			{
				if (*(haystack + l + i) != *(needle + i))
					break ;
				i++;
			}
		}
		if (!*(needle + i))
			return ((char *) haystack + l);
		l++;
	}
	if (!*needle)
		return ((char *) haystack);
	return (NULL);
}
