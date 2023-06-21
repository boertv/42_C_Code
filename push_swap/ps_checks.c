/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:41:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/21 14:20:24 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 1 if stack is sorted, else 0.
// if (as) then checks in ascending order, else in descending.
// if (c) then only looks at the first chunk.
int	ps_issorted(t_stack *a, short as, short c)
{
	t_dlilist	*list;
	size_t		i;

	list = a->start;
	i = 0;
	while (list && list->next)
	{
		if (c && i++ >= a->chunks->size)
			break ;
		if ((as && list->nb > list->next->nb)
			|| (!as && list->nb < list->next->nb))
			return (0);
		list = list->next;
	}
	return (1);
}

// can handle chunk = NULL
void	ps_isnewattribute(t_stack *a, int nb, t_chunk *chunk)
{
	if (a->max < nb)
		a->max = nb;
	if (a->min > nb)
		a->min = nb;
	if (!chunk)
		return ;
	if (chunk->max < nb)
		chunk->max = nb;
	if (chunk->min > nb)
		chunk->min = nb;
}

// can handle chunk = NULL
void	ps_isoldattribute(t_stack *a, int nb, t_chunk *chunk)
{
	if (!a->size)
		return ;
	if (a->max == nb)
		a->max = ps_ismaxmin(a, 1, 0);
	if (a->min == nb)
		a->min = ps_ismaxmin(a, 0, 0);
	if (!chunk)
		return ;
	if (chunk->max == nb)
		chunk->max = ps_ismaxmin(a, 1,
				(chunk == a->chunks) + ((chunk != a->chunks) * 2));
	if (chunk->min == nb)
		chunk->min = ps_ismaxmin(a, 0,
				(chunk == a->chunks) + ((chunk != a->chunks) * 2));
}

// if chunk = NULL it handles the full stack instead.
void	ps_addnewattribute(t_stack *a, int nb, t_chunk *chunk)
{
	if (!chunk)
	{
		a->max = nb;
		a->min = nb;
	}
	else
	{
		chunk->max = nb;
		chunk->min = nb;
	}
}
