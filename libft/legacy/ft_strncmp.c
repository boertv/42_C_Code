/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:15:35 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/10 16:42:24 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s3;
	const unsigned char	*s4;

	s3 = (unsigned char *) s1;
	s4 = (unsigned char *) s2;
	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n && (*(s3 + i) || *(s4 + i)))
	{
		if (*(s3 + i) != *(s4 + i))
			return (*(s3 + i) - *(s4 + i));
		i++;
	}
	return (0);
}
