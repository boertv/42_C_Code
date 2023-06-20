/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:14:36 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/20 16:41:03 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if b = 1 we return 1 if there aren't any above avg values left.
// if b = 0 we return 1 if there aren't any below avg values left.
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

// returns 0 if an operation failed, else 1.
static int	ps_sort_push_del(t_stack *src, t_stack *dst, char csrc)
{
// make this work with chunks of 5 (for both a and b). (and change the cut-off in mother ft)
	if (src->chunks->size == 2)
	{
		if ((csrc == 'a' && src->start->nb != src->chunks->min)
			|| (csrc == 'b' && src->start->nb != src->chunks->max))
			if (!ps_swap(src, csrc))
				return (0);
	}
	while (src->chunks->size)
		if (!ps_push(src, dst, ((csrc == 'a') * 'b') + ((csrc == 'b') * 'a')))
			return (0);
	ps_del_chunk(src);
	if (!dst->chunks->next)
		dst->chunks->s = 1;
	else if (dst->chunks->next->s)
		ps_merge_chunks(dst);
	return (1);
}

// returns 0 if ps_add_emptychunk or an operation failed, else 1
// pushes based on what 'crsc' is (either 'a' or 'b')
// at the end rotates values back in place if there's more than one chunk
static int	ps_push_relative_toavg(t_stack *src, t_stack *dst, char cs)
{
	size_t	r;
	int		avg;

	if (!ps_add_emptychunk(dst))
		return (0);
	if (src->chunks->size < 3 || src->chunks->s)
		return (ps_sort_push_del(src, dst, cs));
	avg = ps_ischunkavg(src);
	r = 0;
	while (src->chunks->size - ((!src->chunks->next) * r)
		&& !ps_ispushdone(src, r, avg, cs - 'a'))
	{
		if ((cs == 'a' && src->start->nb <= avg)
			|| (cs == 'b' && src->start->nb > avg))
		{
			if (!ps_push(src, dst, ((cs == 'a') * 'b') + ((cs == 'b') * 'a')))
				return (0);
		}
		else
		{
			if (!ps_rotate(src, cs))
				return (0);
			r++;
		}
	}
	if (src->chunks->next)
		while (r--)
			if (!ps_rrotate(src, cs))
				return (0);
	if (dst->chunks->next && dst->chunks->next->s)
	{
		if (ps_issorted(dst, (cs == 'b'), 1))
			ps_merge_chunks(dst);
		else if (dst->chunks->size == 2)
		{
			ps_swap(dst, (cs == 'a') + 'a');
			ps_merge_chunks(dst);
		}
	}
	return (1);
}

int	ps_big_sort(t_stack *a, t_stack *b)
{
	if (ps_issorted(a, 1, 0))
		return (1);
	while (!a->chunks->s || b->size)
	{
		while (a->size && !a->chunks->s)
			if (!ps_push_relative_toavg(a, b, 'a'))
				return (0);
		while (b->size && (!a->size || a->chunks->s))
			if (!ps_push_relative_toavg(b, a, 'b'))
				return (0);
	}
	return (1);
}
