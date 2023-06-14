/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:36:30 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/14 17:47:49 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 if malloc failed, else 1
int	ps_add_emptychunk(t_stack *a)
{
	t_chunk	*new;

	new = malloc(sizeof(t_chunk));
	if (!new)
		return (0);
	new->size = 0;
	new->next = a->chunks;
	a->chunks = new;
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
