/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:20:01 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/10 13:12:19 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*s2;

	if (!s1)
		return (NULL);
	l = 0;
	while (*(s1 + l))
		l++;
	s2 = (char *) ft_calloc(l + 1, sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, l + 1);
	return (s2);
}
