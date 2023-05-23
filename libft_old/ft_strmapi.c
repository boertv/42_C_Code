/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:01:22 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/07 16:53:32 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*r;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (*(s + i))
		i++;
	r = (char *) malloc(i + 1);
	if (!r)
		return (NULL);
	*(r + i) = 0;
	while (i-- > 0)
		*(r + i) = (*f)(i, *(s + i));
	return (r);
}
