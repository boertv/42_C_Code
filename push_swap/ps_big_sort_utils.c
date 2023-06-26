/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_big_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:40:08 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/26 19:39:47 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if b = 1 we return 1 if there aren't any above avg values left.
// if b = 0 we return 1 if there aren't any below avg values left.
int	ps_ispushdone(t_stack *src, char b)
{
	t_dlilist	*list;
	size_t		i;

	list = src->start;
	i = 0 + ((!src->chunks->next) * src->chunks->r);
	while (list && src->chunks->size > i
		&& ((!b && list->nb > src->chunks->avg) || (b && list->nb <= src->chunks->avg)))
	{
		list = list->next;
		i++;
	}
	if (!list || src->chunks->size == i)
		return (1);
	return (0);
}

// if src = a and has more than one chunk, we rra and pb in one go.
int	ps_rrotate_chunk_values(t_stack *src, t_stack *dst)
{
	size_t	rr;
	rr = src->chunks->r;
	if (!src->chunks->next)
		return (1);
	if (src->a && rr > 1)
	{
		if (!ps_check_push_result(src, dst))
			return (0);
		if (!ps_add_emptychunk(dst))
			return (0);
	}
	if (rr == 1 && rr--)
		if (!ps_rrotate(src, 1))
			return (0);
	while (rr--)
		if (!ps_rrotate(src, dst->a))
			return (0);
	if (src->a && src->chunks->r > 1)
	{
		src->chunks->avg = ps_ischunkavg(src);
		return (ps_rrotate_with_push(src, dst));
	}
	return (1);
}

static int	ps_rotate_or_swap(t_stack *src, t_stack *dst)
{
	t_dlilist	*list;
	size_t		i;

	list = src->start->next;
	if ((src->a && list->nb <= src->chunks->avg) || (!src->a && list->nb > src->chunks->avg))
	{
		i = 0 + ((!src->chunks->next) * src->chunks->r);
		list = list->next;
		while (list && src->chunks->size > i
			&& ((src->a && list->nb > src->chunks->avg) || (dst->a && list->nb <= src->chunks->avg)))
		{
			list = list->next;
			i++;
		}
		if (!list || src->chunks->size == i)
		{
			if (!ps_swap(src, dst, 1))
				return (0);
			return (1);
		}
	}
	if (!ps_rotate(src, 1))
		return (0);
	src->chunks->r++;
	return (1);
}

// if rr = 1 it adds to src->chunks->r, else it resets to 0.
// returns 0 if an operation failed, else 1.
int	ps_push_or_rotate(t_stack *src, t_stack *dst, short rr)
{
	if (!rr)
		src->chunks->r = 0;
	else if (!src->chunks->next && src->chunks->r >= src->chunks->size)
		return (1);
	while (src->chunks->size - ((!src->chunks->next) * src->chunks->r)
		&& !ps_ispushdone(src, 1 - src->a))
	{
		if ((src->a && src->start->nb <= src->chunks->avg)
			|| (!src->a && src->start->nb > src->chunks->avg))
		{
			if (!ps_push(src, dst))
				return (0);
		}
		else
			if (!ps_rotate_or_swap(src, dst))
				return (0);
	}
	return (1);
}

// returns 0 if operation failed, else 1.
int	ps_check_push_result(t_stack *src, t_stack *dst)
{
	if (!dst->chunks->next && !dst->chunks->s)
	{
		if (ps_issorted(dst, dst->a, 0))
			dst->chunks->s = 1;
		else if (dst->chunks->size == 2)
		{
			if (!ps_swap(dst, src, 1))
				return (0);
			dst->chunks->s = 1;
		}
	}
	else if (dst->chunks->next && dst->chunks->next->s)
	{
		if (ps_issorted(dst, dst->a, 1))
			ps_merge_chunks(dst);
		else if (dst->chunks->size == 2)
		{
			if (!ps_swap(dst, src, 1))
				return (0);
			ps_merge_chunks(dst);
		}
	}
	return (1);
}
