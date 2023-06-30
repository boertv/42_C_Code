/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:14:36 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/30 12:34:40 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 if an operation failed, else 1.
static int	ps_sort_push_del(t_stack *src, t_stack *dst)
{
	if (src->chunks->size == 2)
	{
		if ((src->a && src->start->nb != src->chunks->min)
			|| (!src->a && src->start->nb != src->chunks->max))
			if (!ps_swap(src, dst, 1))
				return (0);
	}
	while (src->chunks->size)
		if (!ps_push(src, dst, 1))
			return (0);
	ps_del_chunk(src);
	if (!dst->chunks->next)
		dst->chunks->s = 1;
	else if (dst->chunks->next->s)
		ps_merge_chunks(dst);
	return (1);
}

// returns 0 if an operation failed, else 1.
static int	ps_pbsapbsbpb_del(t_stack *src, t_stack *dst)
{
	if (!ps_push(src, dst, 1))
		return (0);
	if (!ps_swap(src, dst, 1))
		return (0);
	if (!ps_push(src, dst, 1))
		return (0);
	if (!ps_swap(dst, src, 1))
		return (0);
	if (!ps_push(src, dst, 1))
		return (0);
	ps_del_chunk(src);
	if (!dst->chunks->next)
		dst->chunks->s = 1;
	else if (dst->chunks->next->s)
		ps_merge_chunks(dst);
	return (1);
}

// returns 0 if ps_add_emptychunk or an operation failed, else 1
// pushes based on what 'src' is (either 'a' or 'b')
// at the end rotates values back in place if there's more than one chunk
static int	ps_push_relative_toavg(t_stack *src, t_stack *dst)
{
	if (!ps_add_emptychunk(dst))
		return (0);
	if (src->chunks->size < 3 || src->chunks->s)
		return (ps_sort_push_del(src, dst));
	if (src->chunks->size == 3 && ((src->a
				&& src->chunks->max == src->start->next->nb && src->chunks->min
				!= src->start->nb) || (!src->a && src->chunks->min
				== src->start->next->nb && src->chunks->max != src->start->nb)))
		return (ps_pbsapbsbpb_del(src, dst));
	src->chunks->avg = ps_ischunkavg(src);
	if (!ps_push_or_rotate(src, dst, 0))
		return (0);
	if (!ps_rrotate_chunk_values(src, dst))
		return (0);
	if (!ps_check_push_result(src, dst))
		return (0);
	return (1);
}

int	ps_rrotate_with_push(t_stack *src, t_stack *dst)
{
	size_t	rr;
	int		stop;

	rr = src->chunks->r;
	while (rr--)
		if (!ps_rotate(src, 0))
			return (0);
	if (!ps_push_or_rotate(src, dst, 1))
		return (0);
	while (src->chunks->r--)
	{
		if (!ps_rrotate(src, 1))
			return (0);
		if (src->start->nb <= src->chunks->avg)
		{
			stop = src->start->nb;
			while (src->end->nb < src->start->nb && src->chunks->r--)
				if (!ps_rrotate(src, 1))
					return (0);
			while (dst->start->nb != stop)
				if (!ps_push(src, dst, 1))
					return (0);
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
			if (!ps_push_relative_toavg(a, b))
				return (0);
		while (b->size && (!a->size || a->chunks->s))
			if (!ps_push_relative_toavg(b, a))
				return (0);
	}
	return (1);
}
