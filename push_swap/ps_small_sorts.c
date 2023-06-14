/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_sorts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:07:02 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/14 15:35:54 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_sort_two(t_stack *a)
{
	if (a->start->nb != a->min)
		ps_swap(a, 'a');
}

static void	ps_sort_three(t_stack *a)
{
	if (a->size != 3)
		return ;
	if (ps_issorted(a, 1, 0))
		return ;
	if (a->start->nb < a->start->next->nb)
	{
		ps_rrotate(a, 'a');
		ps_sort_three(a);
	}
	else if (a->start->nb > a->end->nb)
	{
		ps_rotate(a, 'a');
		ps_sort_three(a);
	}
	else
	{
		ps_swap(a, 'a');
		return ;
	}
}

static void	ps_sort_four(t_stack *a, t_stack *b)
{
	if (ps_issorted(a, 1, 0))
		return ;
	ps_fastest_push(a, b, a->min, 'a');
	ps_sort_three(a);
	ps_push(b, a, 'a');
}

static void	ps_sort_five(t_stack *a, t_stack *b)
{
	if (a->size != 5 || b->size)
		return ;
	if (!b->size && ps_issorted(a, 1, 0))
		return ;
	ps_fastest_push(a, b, a->min, 'a');
	ps_fastest_push(a, b, a->min, 'a');
	ps_sort_three(a);
	ps_push(b, a, 'a');
	ps_push(b, a, 'a');
}

void	ps_small_sorts(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		ps_sort_two(a);
	else if (a->size == 3)
		ps_sort_three(a);
	else if (a->size == 4)
		ps_sort_four(a, b);
	else if (a->size == 5)
		ps_sort_five(a, b);
}
