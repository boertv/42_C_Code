/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_attributes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:53:09 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/09 16:52:01 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if (x) then max is calculated, else min.
// don't call with an empty list!! it will just return 0.
int	ps_ismaxmin(t_stack *a, short x)
{
	t_dlilist	*list;
	int			res;

	if (a->size)
		res = a->start->nb;
	else
		return (0);
	list = a->start;
	while (list)
	{
		if ((x && list->nb > res) || (!x && list->nb < res))
			res = list->nb;
		list = list->next;
	}
	return (res);
}

// returns an estimate of the average, good enough to decide on a pivot.
// don't call with an empty list!! it will just return 0.
int	ps_isavg(t_stack *a)
{
	t_dlilist	*list;
	int			avg;
	int			rem;

	list = a->start;
	avg = 0;
	rem = 0;
	while (list)
	{
		avg += list->nb / a->size;
		if (!list->nb / a->size)
			rem += ((list->nb < 0) * -1) + ((list->nb > 0) * 1);
		list = list->next;
	}
	return (avg + (rem / 2));
}

// a->avg needs to be calculated first.
// don't call with an empty list!! it will just return 0.
int	ps_closesttoavg(t_stack *a)
{
	t_dlilist	*list;
	int			cta;

	if (!a->size)
		return (0);
	list = a->start;
	cta = a->start->nb;
	while (list)
	{
		if ((((cta >= a->avg) * (cta - a->avg))
				+ ((cta < a->avg) * (a->avg - cta)))
			> (((list->nb >= a->avg) * (list->nb - a->avg))
				+ ((list->nb < a->avg) * (a->avg - list->nb))))
			cta = list->nb;
		list = list->next;
	}
	return (cta);
}
