/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_manoeuvres.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:56:31 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/15 17:18:04 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pushes 'nb' from 'src' to 'dst' with the least amount of (r)rotates
// returns the amount of rotates performed (+) or rrotates (-), else 0.
// if 'nb' isn't found then also returns 0.
// ignores chunks entirely
int	ps_fastest_push(t_stack *src, t_stack *dst, int nb, char csrc)
{
	size_t		i;
	int			r;

	i = ps_find_nbindex(src, nb);
	if (i == -1)
		return (0);
	if (i < (src->size / 2 + 1))
	{
		r = (int) i;
		while (i--)
			ps_rotate(src, csrc);
	}
	else
	{
		r = (int) src->size - i;
		while (i++ < src->size)
			ps_rrotate(src, csrc);
	}
	ps_push(src, dst, ((csrc == 'a') * 'b') + ((csrc == 'b') * 'a'));
	return (r);
}

// returns -1 if nb isn't in the list.
size_t	ps_find_nbindex(t_stack *a, int nb)
{
	t_dlilist	*list;
	size_t		i;

	list = a->start;
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
