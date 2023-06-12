/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:41:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/12 16:30:42 by bvercaem         ###   ########.fr       */
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

// doesn't update a->cta
// new a->avg is an estimate and should be corrected sometimes (if size > 50)
void	ps_isnewattribute(t_stack *a, int nb)
{
	if (a->max < nb)
		a->max = nb;
	if (a->min > nb)
		a->min = nb;
	// if (a->size <= 50)
	// 	a->avg = ps_isavg(a);
	// else
	// 	a->avg += nb / a->size;
}

// doesn't update a->cta
// new a->avg is an estimate and should be corrected sometimes (if size > 50)
void	ps_isoldattribute(t_stack *a, int nb)
{
	if (!a->size)
		return ;
	if (a->max == nb)
		a->max = ps_ismaxmin(a, 1);
	if (a->min == nb)
		a->min = ps_ismaxmin(a, 0);
	// if (a->size <= 50)
	// 	a->avg = ps_isavg(a);
	// else
	// 	a->avg -= nb / a->size;
}

void	ps_addnewattribute(t_stack *a, int nb)
{
	a->max = nb;
	a->min = nb;
	a->avg = nb;
	a->cta = nb;
}
