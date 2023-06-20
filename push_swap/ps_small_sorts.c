/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_sorts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:07:02 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/20 12:32:23 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 if ps_swap failed, else 1.
static int	ps_sort_two(t_stack *a)
{
	if (a->start->nb != a->min)
		if (!ps_swap(a, 'a'))
			return (0);
	return (1);
}

// returns 0 if ps_swap failed, else 1.
static int	ps_sort_three(t_stack *a)
{
	if (ps_issorted(a, 1, 0))
		return (1);
	if (a->start->nb < a->start->next->nb)
	{
		if (!ps_rrotate(a, 'a') || !ps_sort_three(a))
			return (0);
	}
	else if (a->start->nb > a->end->nb)
	{
		if (!ps_rotate(a, 'a') || !ps_sort_three(a))
			return (0);
	}
	if (!ps_swap(a, 'a'))
		return (0);
	return (1);
}

// returns 0 if an operation failed, else 1.
static int	ps_sort_four(t_stack *a, t_stack *b)
{
	if (ps_issorted(a, 1, 0))
		return (1);
	if (ps_fastest_push(a, b, a->min, 'a') == -1)
		return (0);
	if (!ps_sort_three(a))
		return (0);
	if (!ps_push(b, a, 'a'))
		return (0);
	return (1);
}

// returns 0 if an operation failed, else 1.
static int	ps_sort_five(t_stack *a, t_stack *b)
{
	if (!b->size && ps_issorted(a, 1, 0))
		return (1);
	if (ps_fastest_push(a, b, a->min, 'a') == -1)
		return (0);
	if (ps_fastest_push(a, b, a->min, 'a') == -1)
		return (0);
	if (!ps_sort_three(a))
		return (0);
	if (!ps_push(b, a, 'a') || !ps_push(b, a, 'a'))
		return (0);
	return (1);
}

// returns 0 if an operation failed, else 1.
int	ps_small_sorts(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		return (ps_sort_two(a));
	else if (a->size == 3)
		return (ps_sort_three(a));
	else if (a->size == 4)
		return (ps_sort_four(a, b));
	else if (a->size == 5)
		return (ps_sort_five(a, b));
	return (0);
}
