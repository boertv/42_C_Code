/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:44:23 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/18 17:42:41 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// if chars is an empty string a ptr to the terminating 0 of s is returned.
char	*ft_strchrs(const char *s, const char *chars)
{
	if (!s || !chars)
		return (NULL);
	while (*s)
	{
		if (ft_strchr(chars, *s))
			return ((char *) s);
		s++;
	}
	if (!*chars)
		return ((char *) s);
	return (NULL);
}
