/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:37:23 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/17 11:31:13 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	char			*bu;

	if (!len)
		return (b);
	if (!b)
		return (NULL);
	ch = (unsigned char) c;
	bu = (char *) b;
	while (len-- > 0)
		*(bu + len) = ch;
	return ((void *) bu);
}
