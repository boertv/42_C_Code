/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:14:36 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/14 15:56:22 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_ischunkbelowavg(t_stack *a, size_t r, int avg)
{
	t_dlilist	*list;

	list = a->start;
	while (list && a->chunks->size > r && list->nb <= avg)
	{
		list = list->next;
		r++;
	}
	if (!list || a->chunks->size == r)
		return (1);
	return (0);
}

// returns 0 if ps_add_emptychunk malloc failed, else 1
// at the end rotates values back in place if there's more than one chunk
static int	ps_push_aboveavg(t_stack *src, t_stack *dst, char csrc)
{
	size_t	r;
	int		avg;

	if (!ps_add_emptychunk(dst))
		return (0);
	avg = ps_ischunkavg(src);
	r = 0;
	while (src->chunks->size && src->start->nb > avg)
		ps_push(src, dst, ((csrc == 'a') * 'b') + ((csrc == 'b') * 'a'));
	while (src->chunks->size > r && !ps_ischunkbelowavg(src, r, avg))
	{
		if (src->start->nb > avg)
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
// push smaller than avg from a, push larger than avg from b.
	if (!ps_push_aboveavg(a, b, 'a'))
		return (0);
// temp return
return (1);
}
