/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:34:28 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/21 12:51:40 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Removes start- and end-characters regardless of order.
// Should 'if (!set && s1)' return strdup(s1)? Feel like we want an error
//  instead of output that is probably unwanted.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	l = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (*(s1 + l))
		l++;
	if (l)
		l--;
	while (l && ft_strchr(set, *(s1 + l)))
		l--;
	if (*s1)
		l++;
	s2 = (char *) malloc((l + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	*(s2 + l) = 0;
	while (l-- > 0)
		*(s2 + l) = *(s1 + l);
	return (s2);
}
