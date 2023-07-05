/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:11:29 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/24 16:48:52 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_error(const char *error)
{
	write (1, "an error occured in ft_calloc", 29);
	if (error)
	{
		write (1, " concerning { ", 14);
		write (1, error, ft_strlen(error));
		write (1, " }", 2);
	}
	write (1, "\n\n", 2);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	range;

	range = count * size;
	if (size && (count != range / size))
		return (ft_error("overflow"));
	if (!range)
		return (ft_error("range of 0"));
	p = malloc(range);
	if (!p)
		return (ft_error("malloc error"));
	ft_bzero(p, range);
	return (p);
}
