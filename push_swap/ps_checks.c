/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:41:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/08 16:47:23 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 1 if stack is sorted, else 0.
// if (as) then checks in ascending order, else in descending.
int	ps_issorted(t_stack *a, short as)
{
	t_dlilist	*list;

	list = a->start;
	while (list && list->next)
	{
		if ((as && list->nb > list->next->nb)
			|| (!as && list->nb < list->next->nb))
			return (0);
		list = list->next;
	}
	return (1);
}

void	ps_isnewattribute(t_stack *a, int nb)
{
	if (a->max < nb)
		a->max = nb;
	if (a->min > nb)
		a->min = nb;
}

void	ps_isoldattribute(t_stack *a, int nb)
{
	if (!a->size)
		return ;
	if (a->max == nb)
		a->max = ps_ismaxmin(a, 1);
	if (a->min == nb)
		a->min = ps_ismaxmin(a, 0);
}

void	ps_addnewattribute(t_stack *a, int nb)
{
	a->max = nb;
	a->min = nb;
}

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
