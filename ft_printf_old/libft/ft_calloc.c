/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:11:29 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/17 11:15:27 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Will allocate 1 byte when range == 0;
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	range;

	range = count * size;
	if (size && (count != range / size))
		return (NULL);
	if (!range)
		range = 1;
	p = malloc(range);
	if (!p)
		return (NULL);
	ft_bzero(p, range);
	return (p);
}
