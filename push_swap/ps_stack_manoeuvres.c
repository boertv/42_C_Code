/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_manoeuvres.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:56:31 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/30 12:36:07 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pushes 'nb' from 'src' to 'dst' with the least amount of (r)rotates
// returns the amount of rotates performed.
// returns -1 if an operation failed, or nb wasn't found.
// ignores chunks entirely and always prints all operations.
int	ps_fastest_push(t_stack *src, t_stack *dst, int nb)
{
	ssize_t		i;
	int			r;

	i = ps_find_nbindex(src, nb);
	if (i == -1)
		return (-1);
	if (i < ((ssize_t)(src->size / 2 + 1)))
	{
		r = (int) i;
		while (i--)
			if (!ps_rotate(src, 1))
				return (-1);
	}
	else
		while (i++ < (ssize_t) src->size)
			if (!ps_rrotate(src, 1))
				return (-1);
	if (!ps_push(src, dst, 1))
		return (-1);
	return (r);
}

// returns -1 if nb isn't in the list.
ssize_t	ps_find_nbindex(t_stack *s, int nb)
{
	t_dlilist	*list;
	ssize_t		i;

	list = s->start;
	i = 0;
	while (list && list->nb != nb)
	{
		i++;
		list = list->next;
	}
	if (!list)
		return (-1);
	return (i);
}
