/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:38:42 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/18 17:20:55 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DOESN'T FREE
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = 0;
	l2 = 0;
	while (*(s1 + l1))
		l1++;
	while (*(s2 + l2))
		l2++;
	r = (char *) malloc((l1 + l2 + 1) * sizeof(char));
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, l1 + 1);
	ft_strlcpy(r + l1, s2, l2 + 1);
	return (r);
}
