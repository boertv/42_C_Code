/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_big_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:40:08 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/23 17:55:00 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if b = 1 we return 1 if there aren't any above avg values left.
// if b = 0 we return 1 if there aren't any below avg values left.
int	ps_ispushdone(t_stack *s, size_t r, int avg, char b)
{
	t_dlilist	*list;
	size_t		i;

	list = s->start;
	i = 0 + ((!s->chunks->next) * r);
	while (list && s->chunks->size > i
		&& ((!b && list->nb > avg) || (b && list->nb <= avg)))
	{
		list = list->next;
		i++;
	}
	if (!list || s->chunks->size == i)
		return (1);
	return (0);
}

static int	ps_rrotate_chunk_values(t_stack *src, size_t r)
{
	if (src->chunks->next)
		while (r--)
			if (!ps_rrotate(src, 1))
				return (0);
	return (1);
}

static int	ps_rotate_or_swap(t_stack *src, t_stack *dst, size_t *r, int avg)
{
	t_dlilist	*list;
	size_t		i;

	list = src->start->next;
	if ((src->a && list->nb <= avg) || (!src->a && list->nb > avg))
	{
		i = 0 + ((!src->chunks->next) * (*r));
		list = list->next;
		while (list && src->chunks->size > i
			&& ((src->a && list->nb > avg) || (dst->a && list->nb <= avg)))
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
	(*r)++;
	return (1);
}

int	ps_push_or_rotate(t_stack *src, t_stack *dst)
{
	size_t	r;
	int		avg;

	avg = ps_ischunkavg(src);
	r = 0;
	while (src->chunks->size - ((!src->chunks->next) * r)
		&& !ps_ispushdone(src, r, avg, 1 - src->a))
	{
		if ((src->a && src->start->nb <= avg)
			|| (!src->a && src->start->nb > avg))
		{
			if (!ps_push(src, dst))
				return (0);
		}
		else
			if (!ps_rotate_or_swap(src, dst, &r, avg))
				return (0);
	}
	return (ps_rrotate_chunk_values(src, r));
}
