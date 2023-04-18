/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:36:27 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/17 11:58:30 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Should len == 0 and s == NULL return an empty string instead of NULL?
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*r;

	if (!s)
		return (NULL);
	i = 0;
	while (*(s + i))
		i++;
	if (i < start)
	{
		len = 0;
		start = 0;
	}
	i = 0;
	while (*(s + start + i) && i < len)
		i++;
	r = (char *) malloc((i + 1) * sizeof(char));
	if (!r)
		return (NULL);
	ft_strlcpy(r, s + start, i + 1);
	return (r);
}
