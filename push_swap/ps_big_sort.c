/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:14:36 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/14 17:57:05 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if b == 1 we return 0 if there are above avg values left.
static int	ps_ispushdone(t_stack *a, size_t r, int avg, char b)
{
	t_dlilist	*list;
	size_t		i;

	list = a->start;
	i = 0 + ((!a->chunks->next) * r);
	while (list && a->chunks->size > i
		&& ((!b && list->nb > avg) || (b && list->nb <= avg)))
	{
		list = list->next;
		i++;
	}
	if (!list || a->chunks->size == i)
		return (1);
	return (0);
}

static int	ps_sort_push_del(t_stack *src, t_stack *dst, char csrc)
{
// make this work with chunks of 5.
	if (src->chunks->size == 2)
	{
		if ((csrc == 'a' && src->start->nb != src->chunks->min)
			|| (csrc == 'b' && src->start->nb != src->chunks->max))
			ps_swap(src, csrc);
	}
	while (src->chunks->size)
		ps_push(src, dst, ((csrc == 'a') * 'b') + ((csrc == 'b') * 'a'));
	ps_del_chunk(src);
	return (1);
}

// returns 0 if ps_add_emptychunk malloc failed, else 1
// pushes based on what 'crsc' is (either 'a' or 'b')
// at the end rotates values back in place if there's more than one chunk
static int	ps_push_relative_toavg(t_stack *src, t_stack *dst, char csrc)
{
	size_t	r;
	int		avg;

	if (!ps_add_emptychunk(dst))
		return (0);
	if (src->chunks->size < 3)
		return (ps_sort_push_del(src, dst, csrc));
	avg = ps_ischunkavg(src);
	r = 0;
	while (src->chunks->size - ((!src->chunks->next) * r)
		&& !ps_ispushdone(src, r, avg, csrc - 'a'))
	{
		if ((csrc == 'a' && src->start->nb <= avg)
			|| (csrc == 'b' && src->start->nb > avg))
			ps_push(src, dst, ((csrc == 'a') * 'b') + ((csrc == 'b') * 'a'));
		else
		{
			ps_rotate(src, csrc);
			r++;
		}
	}
	if (src->chunks->next)
		while (r--)
			ps_rrotate(src, csrc);
	return (1);
}

int	ps_big_sort(t_stack *a, t_stack *b)
{
	while (!ps_issorted(a, 1, 0))
	{
		while (a->size)
		{
			if (ps_issorted(a, 1, 0))
				break ;
			if (!ps_push_relative_toavg(a, b, 'a'))
				return (0);
		}
		while (b->size)
			if (!ps_push_relative_toavg(b, a, 'b'))
				return (0);
	}
	return (1);
}
