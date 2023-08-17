/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:26:30 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/06 16:31:13 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char) c;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == ch)
			return ((char *) s);
		s++;
	}
	if (!ch)
		return ((char *) s);
	return (NULL);
}
