/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:36:30 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/23 16:25:14 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns NULL if start = NULL.
t_chunk	*ps_get_last_chunk(t_chunk *start)
{
	t_chunk	*last;

	if (!start)
		return (NULL);
	last = start;
	while (last->next)
		last = last->next;
	return (last);
}

// returns 0 if malloc failed, else 1
int	ps_add_emptychunk(t_stack *s)
{
	t_chunk	*new;

	new = malloc(sizeof(t_chunk));
	if (!new)
		return (0);
	new->size = 0;
	new->s = 0;
	new->next = s->chunks;
	s->chunks = new;
	return (1);
}

// merges the top two chunks and then frees the second one if possible.
// returns 0 if there are less than two chunks, else 1.
int	ps_merge_chunks(t_stack *s)
{
	t_chunk	*bin;

	if (!s->chunks || !s->chunks->next)
		return (0);
	bin = s->chunks->next;
	s->chunks->size += bin->size;
	if (bin->max > s->chunks->max)
		s->chunks->max = bin->max;
	if (bin->min < s->chunks->min)
		s->chunks->min = bin->min;
	if (bin->s)
		s->chunks->s = 1;
	s->chunks->next = bin->next;
	free(bin);
	return (1);
}

// returns 0 if there are no chunks.
int	ps_del_chunk(t_stack *s)
{
	t_chunk	*bin;

	if (!s->chunks)
		return (0);
	bin = s->chunks;
	s->chunks = s->chunks->next;
	free(bin);
	return (1);
}
