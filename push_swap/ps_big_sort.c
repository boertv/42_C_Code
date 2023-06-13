/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:14:36 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/13 15:03:05 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_ischunkbelowavg(t_stack *a, size_t r)
{
	t_dlilist	*list;

	list = a->start;
	while (list && a->chunks->size > r && list->nb <= a->avg)
	{
		list = list->next;
		r++;
	}
	if (!list || a->chunks->size == r)
		return (1);
	return (0);
}

static void	ps_calculate_new_avgs(t_stack *src, t_stack *dst)
{
// update isavg ft first to work with chunks.
}

// rotates values back in place if there's more than one chunk
static int	ps_push_aboveavg(t_stack *src, t_stack *dst, char csrc)
{
	size_t	r;

	if (!ps_add_emptychunk(dst->chunks))
		return (0);
	r = 0;
	while (src->chunks->size && src->start->nb > src->avg)
		ps_push(src, dst, ((csrc == 'a') * 'b') + ((csrc == 'b') * 'a'));
	while (src->chunks->size > r && !ps_ischunkbelowavg(src, r))
	{
		if (src->start->nb > src->avg)
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
	ps_calculate_new_avgs(src, dst);
	return (1);
}

int	ps_big_sort(t_stack *a, t_stack *b)
{
	if (!ps_add_emptychunk(a->chunks))
		return (0);
	a->chunks->size = a->size;
	a->avg = ps_isavg(a);
}
