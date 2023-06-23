/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:14:36 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/23 15:06:34 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 if an operation failed, else 1.
static int	ps_sort_push_del(t_stack *src, t_stack *dst, char csrc)
{
	if (src->chunks->size == 2)
	{
		if ((csrc == 'a' && src->start->nb != src->chunks->min)
			|| (csrc == 'b' && src->start->nb != src->chunks->max))
			if (!ps_swap(src, dst, csrc))
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

// returns 0 if an operation failed, else 1.
static int	ps_pbsapbsbpb_del(t_stack *src, t_stack *dst, char cs)
{
	if (!ps_push(src, dst, (cs == 'a') + 'a'))
		return (0);
	if (!ps_swap(src, dst, cs))
		return (0);
	if (!ps_push(src, dst, (cs == 'a') + 'a'))
		return (0);
	if (!ps_swap(dst, src, (cs == 'a') + 'a'))
		return (0);
	if (!ps_push(src, dst, (cs == 'a') + 'a'))
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
	if (!ps_add_emptychunk(dst))
		return (0);
	if (src->chunks->size < 3 || src->chunks->s)
		return (ps_sort_push_del(src, dst, cs));
	if (src->chunks->size == 3 && ((cs == 'a'
				&& src->chunks->max == src->start->next->nb && src->chunks->min
				!= src->start->nb) || (cs == 'b' && src->chunks->min
				== src->start->next->nb && src->chunks->max != src->start->nb)))
		return (ps_pbsapbsbpb_del(src, dst, cs));
	if (!ps_push_or_rotate(src, dst, cs))
		return (0);
	if (dst->chunks->next && dst->chunks->next->s)
	{
		if (ps_issorted(dst, (cs == 'b'), 1))
			ps_merge_chunks(dst);
		else if (dst->chunks->size == 2)
		{
			if (!ps_swap(dst, src, (cs == 'a') + 'a'))
				return (0);
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
