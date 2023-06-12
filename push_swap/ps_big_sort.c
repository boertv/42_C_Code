/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:14:36 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/12 17:03:45 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_isbelowavguntil(t_stack *a, int stop)
{
	t_dlilist	*list;

	list = a->start;
	while (list && list->nb != stop && list->nb <= a->avg)
		list = list->next;
	if (list && list->nb == stop)
		return (1);
	return (0);
}

static void	*ps_push_aboveavg(t_stack *src, t_stack *dst, char csrc)
{
	size_t	*chunk;
	int		stop;

	chunk = malloc(sizeof(size_t));
	if (!chunk)
		return (NULL);
	*chunk = 0;
	while (src->start->nb > src->avg)
	{
		ps_push(src, dst, ((csrc == 'a') * 'b') + ((csrc == 'b') * 'a'));
		*chunk++;
	}
	stop = src->start->nb;
	while (!ps_isbelowavguntil(src, stop))
	{
		if (src->start->nb > src->avg)
		{
			ps_push(src, dst, ((csrc == 'a') * 'b') + ((csrc == 'b') * 'a'));
			*chunk++;
		}
		else
			ps_rotate(src, csrc);
	}
	src->avg = ps_isavg(src);
	dst->avg = ps_isavg(dst);
}

int	ps_big_sort(t_stack *a, t_stack *b)
{
	ps_add_chunk(b->chunks, ps_push_aboveavg(a, b, 'a'));
}
