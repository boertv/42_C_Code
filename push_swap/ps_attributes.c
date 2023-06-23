/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_attributes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:53:09 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/23 16:05:44 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_ismaxminlastchunk(t_stack *s, short x)
{
	t_dlilist	*list;
	t_chunk		*chunk;
	int			res;
	size_t		i;

	res = s->end->nb;
	list = s->end;
	i = 0;
	chunk = s->chunks;
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
int	ps_ismaxmin(t_stack *s, short x, short c)
{
	t_dlilist	*list;
	int			res;
	size_t		i;

	if (!s->start || (c && !s->chunks))
		return (0);
	else
		res = s->start->nb;
	if (c == 2)
		return (ps_ismaxminlastchunk(s, x));
	list = s->start;
	i = 0;
	while (list)
	{
		if (c && i++ >= s->chunks->size)
			break ;
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

static int	ps_best_middle(t_stack *s, int mida, int midb)
{
	t_dlilist	*list;
	size_t		i;
	size_t		counta;
	size_t		countb;

	list = s->start;
	i = 0;
	counta = 0;
	countb = 0;
	while (list && i++ < s->chunks->size)
	{
		if (list->nb > mida)
			counta++;
		if (list->nb > midb)
			countb++;
		list = list->next;
	}
	if (counta == 0 && countb == 0)
		return (s->chunks->max - 1);
	if (counta == countb)
		return (mida);
	counta = ps_recalculate_count(counta, s->chunks->size / 2);
	countb = ps_recalculate_count(countb, s->chunks->size / 2);
	return (((counta <= countb) * mida) + ((counta > countb) * midb));
}

// returns an estimate of the median, good enough to decide on s pivot.
// don't call with an empty list/chunk!! will just return 0.
int	ps_ischunkavg(t_stack *s)
{
	t_dlilist	*list;
	int			avga;
	int			avgm;
	int			rem;
	size_t		i;

	list = s->start;
	avga = 0;
	rem = 0;
	i = 0;
	while (list && i++ < s->chunks->size)
	{
		avga += (list->nb / s->chunks->size);
		if (!(list->nb / s->chunks->size))
			rem += (((list->nb < 0) * -1) + ((list->nb > 0) * 1));
		list = list->next;
	}
	avga = avga + (rem / 2);
	avgm = (s->chunks->max + s->chunks->min) / 2;
	return (ps_best_middle(s, avga, avgm));
}
