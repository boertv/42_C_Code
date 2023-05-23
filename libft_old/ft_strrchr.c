/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:51:35 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/17 11:45:42 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			ch;
	unsigned long	i;

	if (!s)
		return (NULL);
	ch = (char) c;
	i = 0;
	while (*(s + i))
		i++;
	if (!ch)
		return ((char *)(s + i));
	while (i-- > 0)
	{
		if (*(s + i) == ch)
			return ((char *)(s + i));
	}
	return (NULL);
}
