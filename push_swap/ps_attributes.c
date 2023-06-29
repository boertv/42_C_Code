/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_attributes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:53:09 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/29 16:09:28 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if (x) then max is calculated, else min.
// don't call with an empty list!! it will just return 0.
static int	ps_ismaxminlastchunk(t_stack *s, short x)
{
	t_dlilist	*list;
	t_chunk		*chunk;
	int			res;
	size_t		i;

	if (!s->end)
		return (0);
	res = s->end->nb;
	list = s->end;
	i = 0;
	chunk = ps_get_last_chunk(s->chunks);
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

static int	*ps_list_to_array(t_stack *s)
{
	t_dlilist	*list;
	int			*new;
	int			*array;

	if (!s || !s->size || !s->start)
		return (NULL);
	list = s->start;
	new = malloc(sizeof(int) * s->size);
	if (!new)
		return (NULL);
	array = new;
	while (list)
	{
		*array = list->nb;
		array++;
		list = list->next;
	}
	return (new);
}

static int	*ps_bubble_sort(int *a, size_t n)
{
	size_t	i;
	int		temp;

	while (a && n--)
	{
		i = 0;
		temp = 0;
		while (i < n)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				if (!temp)
					temp = 1;
			}
			i++;
		}
		if (!temp)
			break ;
	}
	return (a);
}

// don't call with an empty list/chunk!! will just return 0.
// sets indexes for all elements, doesn't calculate a median just yet.
int	ps_set_indexes(t_stack *s)
{
	int			*a;
	t_dlilist	*list;
	size_t		i;

	if (s->size < 2)
		return (1);
	a = ps_bubble_sort(ps_list_to_array(s), s->size);
	i = 0;
	while (a && i < s->size)
	{
		list = s->start;
		while (list && list->nb != a[i])
			list = list->next;
		if (!list)
			break ;
		list->index = i;
		i++;
	}
	if (a)
		free(a);
	if (!a || !list)
		return (0);
	return (1);
}
