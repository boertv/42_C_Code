/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:11:26 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/07 16:38:07 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// frees all a[n] and a, then returns NULL.
// a has to be NULL terminated.
char	**ft_clear_da(char **a)
{
	size_t	i;

	if (!a)
		return (NULL);
	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (NULL);
}

static size_t	ft_alength(char const *s, char c)
{
	size_t	al;

	al = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			al++;
		s++;
	}
	return (al);
}

static char	**ft_fill(char **a, size_t al, char const *s, char c)
{
	size_t	sl;

	sl = 0;
	while (*s)
	{
		if (*s != c)
		{
			sl = 0;
			while (*(s + sl) && *(s + sl) != c)
				sl++;
			*(a + al) = (char *) malloc((sl + 1) * sizeof(char));
			if (!*(a + al))
				return (ft_clear_da(a));
			*(*(a + al) + sl) = 0;
			while (sl-- > 0)
				*(*(a + al) + sl) = *(s + sl);
			while (*s && *s != c)
				s++;
			al++;
		}
		if (*s)
			s++;
	}
	*(a + al) = NULL;
	return (a);
}

char	**ft_split(char const *s, char c)
{
	size_t	al;
	char	**a;

	if (!s)
		return (NULL);
	al = ft_alength(s, c);
	a = (char **) malloc((al + 1) * sizeof(char *));
	if (!a)
		return (NULL);
	return (ft_fill(a, 0, s, c));
}
