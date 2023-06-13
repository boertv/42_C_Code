/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_attributes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:53:09 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/13 17:22:58 by bvercaem         ###   ########.fr       */
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

static int	ps_isdecentmiddlepercent(t_stack *a, int middle)
{
	t_dlilist	*list;
	size_t		i;
	size_t		count;

	if (middle <= 5 && -5 <= middle)
		return (1);
	list = a->start;
	i = 0;
	count = 0;
	while (list && i++ < a->chunks->size)
	{
		if (list->nb > middle)
			count++;
		list = list->next;
	}
	if (!count)
		return (-1);
	if (a->chunks->size / count > 4)
		return (0);
	return (1);
}

// returns an estimate of the median, good enough to decide on a pivot.
// don't call with an empty list/chunk!! it will just return 0.
int	ps_ischunkavg(t_stack *a)
{
//this shit is so fucked
	t_dlilist	*list;
	int			avg;
	int			rem;
	size_t		i;

	list = a->start;
	avg = 0;
	rem = 0;
	i = 0;
	while (list && i++ < a->chunks->size)
	{
		avg += (list->nb / a->chunks->size);
		if (!(list->nb / a->chunks->size))
			rem += (((list->nb < 0) * -1) + ((list->nb > 0) * 1));
		list = list->next;
	}
	list = a->start;
	avg = avg + (rem / 2);
//ft_printf("chunk size = %i  avg = %i\n", a->chunks->size, avg);
	while (!ps_isdecentmiddlepercent(a, avg))
		avg = avg / 5 * 4;
	if (ps_isdecentmiddlepercent(a, avg) == -1)
		avg = avg / 4 * 5;
//ft_printf("chunk size = %i  avg = %i\n", a->chunks->size, avg);
	return (avg);
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
