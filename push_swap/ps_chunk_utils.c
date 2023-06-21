/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:36:30 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/21 15:25:33 by bvercaem         ###   ########.fr       */
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
int	ps_add_emptychunk(t_stack *a)
{
	t_chunk	*new;

	new = malloc(sizeof(t_chunk));
	if (!new)
		return (0);
	new->size = 0;
	new->s = 0;
	new->next = a->chunks;
	a->chunks = new;
	return (1);
}

// merges the top two chunks and then frees the second one if possible.
// returns 0 if there are less than two chunks, else 1.
int	ps_merge_chunks(t_stack *a)
{
	t_chunk	*bin;

	if (!a->chunks || !a->chunks->next)
		return (0);
	bin = a->chunks->next;
	a->chunks->size += bin->size;
	if (bin->max > a->chunks->max)
		a->chunks->max = bin->max;
	if (bin->min < a->chunks->min)
		a->chunks->min = bin->min;
	if (bin->s)
		a->chunks->s = 1;
	a->chunks->next = bin->next;
	free(bin);
	return (1);
}

// returns 0 if there are no chunks.
int	ps_del_chunk(t_stack *a)
{
	t_chunk	*bin;

	if (!a->chunks)
		return (0);
	bin = a->chunks;
	a->chunks = a->chunks->next;
	free(bin);
	return (1);
}
