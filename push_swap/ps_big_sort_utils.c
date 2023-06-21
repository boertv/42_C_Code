/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_big_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:40:08 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/21 15:29:10 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if b = 1 we return 1 if there aren't any above avg values left.
// if b = 0 we return 1 if there aren't any below avg values left.
int	ps_ispushdone(t_stack *a, size_t r, int avg, char b)
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

int	ps_push_or_rotate(t_stack *src, t_stack *dst, char cs)
{
	size_t	r;
	int		avg;

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
		else if (!ps_rotate(src, cs))
			return (0);
		else
			r++;
	}
	if (src->chunks->next)
		while (r--)
			if (!ps_rrotate(src, cs))
				return (0);
	return (1);
}
