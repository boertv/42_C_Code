/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_attributes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:53:09 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/14 15:51:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_ismaxminlastchunk(t_stack *a, short x)
{
	t_dlilist	*list;
	t_chunk		*chunk;
	int			res;
	size_t		i;

	res = a->end->nb;
	list = a->end;
	i = 0;
	chunk = a->chunks;
	while (chunk->next)
		chunk = chunk->next;
	while (list && i++ < chunk->size)
	{
		if ((x && list->nb > res) || (!x && list->nb < res))
			res = list->nb;
		list = list->prev;
	}
	return (res);
}

// if (x) then max is calculated, else min.
// c = 0: look at all/ c = 1: look at first chunk/ c = 2: look at last chunk.
// don't call with an empty list!! it will just return 0.
int	ps_ismaxmin(t_stack *a, short x, short c)
{
	t_dlilist	*list;
	int			res;
	size_t		i;

	if (!a->start || (c && !a->chunks))
		return (0);
	else
		res = a->start->nb;
	if (c == 2)
		return (ps_ismaxminlastchunk(a, x));
	list = a->start;
	i = 0;
	while (list)
	{
		if (c && i++ >= a->chunks->size)
			break;
		if ((x && list->nb > res) || (!x && list->nb < res))
			res = list->nb;
		list = list->next;
	}
	return (res);
}

static size_t	ps_recalculate_count(size_t count, size_t halfsize)
{
	if (count >= halfsize)
		count = count - halfsize;
	else
		count = halfsize - count;
	return (count);
}

static int	ps_best_middle(t_stack *a, int mida, int midb)
{
	t_dlilist	*list;
	size_t		i;
	size_t		counta;
	size_t		countb;

	list = a->start;
	i = 0;
	counta = 0;
	countb = 0;
	while (list && i++ < a->chunks->size)
	{
		if (list->nb > mida)
			counta++;
		if (list->nb > midb)
			countb++;
		list = list->next;
	}
	if (counta == 0 && countb == 0)
		return (a->chunks->max - 4);
	if (counta == countb)
		return (mida);
	counta = ps_recalculate_count(counta, a->chunks->size / 2);
	countb = ps_recalculate_count(countb, a->chunks->size / 2);
	return (((counta <= countb) * mida) + ((counta > countb) * midb));
}

// returns an estimate of the median, good enough to decide on a pivot.
// don't call with an empty list/chunk!! will just return 0.
int	ps_ischunkavg(t_stack *a)
{
	t_dlilist	*list;
	int			avga;
	int			avgm;
	int			rem;
	size_t		i;

	list = a->start;
	avga = 0;
	rem = 0;
	i = 0;
	while (list && i++ < a->chunks->size)
	{
		avga += (list->nb / a->chunks->size);
		if (!(list->nb / a->chunks->size))
			rem += (((list->nb < 0) * -1) + ((list->nb > 0) * 1));
		list = list->next;
	}
	avga = avga + (rem / 2);
	avgm = (a->chunks->max + a->chunks->min) / 2;
	return (ps_best_middle(a, avga, avgm));
}
