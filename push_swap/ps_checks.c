/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:41:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/23 16:24:22 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 1 if stack is sorted, else 0.
// if (as) then checks in ascending order, else in descending.
// if (c) then only looks at the first chunk.
int	ps_issorted(t_stack *s, short as, short c)
{
	t_dlilist	*list;
	size_t		i;

	list = s->start;
	i = 0;
	while (list && list->next)
	{
		if (c && i++ >= s->chunks->size)
			break ;
		if ((as && list->nb > list->next->nb)
			|| (!as && list->nb < list->next->nb))
			return (0);
		list = list->next;
	}
	return (1);
}

// can handle chunk = NULL
void	ps_isnewattribute(t_stack *s, int nb, t_chunk *chunk)
{
	if (s->max < nb)
		s->max = nb;
	if (s->min > nb)
		s->min = nb;
	if (!chunk)
		return ;
	if (chunk->max < nb)
		chunk->max = nb;
	if (chunk->min > nb)
		chunk->min = nb;
}

// can handle chunk = NULL
void	ps_isoldattribute(t_stack *s, int nb, t_chunk *chunk)
{
	if (!s->size)
		return ;
	if (s->max == nb)
		s->max = ps_ismaxmin(s, 1, 0);
	if (s->min == nb)
		s->min = ps_ismaxmin(s, 0, 0);
	if (!chunk)
		return ;
	if (chunk->max == nb)
		chunk->max = ps_ismaxmin(s, 1,
				(chunk == s->chunks) + ((chunk != s->chunks) * 2));
	if (chunk->min == nb)
		chunk->min = ps_ismaxmin(s, 0,
				(chunk == s->chunks) + ((chunk != s->chunks) * 2));
}

// if chunk = NULL it handles the full stack instead.
void	ps_addnewattribute(t_stack *s, int nb, t_chunk *chunk)
{
	if (!chunk)
	{
		s->max = nb;
		s->min = nb;
	}
	else
	{
		chunk->max = nb;
		chunk->min = nb;
	}
}
