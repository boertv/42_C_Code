/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:09:33 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/21 14:21:50 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns NULL if malloc failed
t_dlilist	*ps_create_element(int nb)
{
	t_dlilist	*el;

	el = (t_dlilist *) malloc(sizeof(t_dlilist));
	if (!el)
		return (NULL);
	el->nb = nb;
	el->next = NULL;
	el->prev = NULL;
	return (el);
}

// returns 0 if el == NULL, else 1
int	ps_add_front(t_stack *a, t_dlilist *el)
{
	if (!el)
		return (0);
	el->prev = NULL;
	el->next = a->start;
	a->size++;
	if (a->chunks && !a->chunks->size)
		ps_addnewattribute(a, el->nb, a->chunks);
	if (a->chunks)
		a->chunks->size++;
	if (!a->start)
	{
		a->end = el;
		ps_addnewattribute(a, el->nb, NULL);
	}
	else
	{
		a->start->prev = el;
		ps_isnewattribute(a, el->nb, a->chunks);
	}
	a->start = el;
	return (1);
}

// returns 0 if el == NULL, else 1
int	ps_add_back(t_stack *a, t_dlilist *el)
{
	t_chunk	*chunk;

	if (!el)
		return (0);
	el->next = NULL;
	el->prev = a->end;
	a->size++;
	chunk = a->chunks;
	while (chunk && chunk->next)
		chunk = chunk->next;
	if (chunk && !chunk->size)
		ps_addnewattribute(a, el->nb, chunk);
	if (chunk)
		chunk->size++;
	if (!a->end)
	{
		a->start = el;
		ps_addnewattribute(a, el->nb, NULL);
	}
	else
	{
		a->end->next = el;
		ps_isnewattribute(a, el->nb, chunk);
	}
	a->end = el;
	return (1);
}

// returns 0 if list is empty, else 1
// if f == 1 the data is freed
int	ps_del_front(t_stack *a, short f)
{
	t_dlilist	*bin;

	if (!a->size)
		return (0);
	bin = a->start;
	a->start = a->start->next;
	if (!a->start)
		a->end = NULL;
	else
		a->start->prev = NULL;
	a->size--;
	if (a->chunks)
		a->chunks->size--;
	ps_isoldattribute(a, bin->nb, a->chunks);
	if (f == 1)
		free(bin);
	return (1);
}

// returns 0 if list is empty, else 1
// if f == 1 the data is freed
int	ps_del_back(t_stack *a, short f)
{
	t_dlilist	*bin;
	t_chunk		*chunk;

	if (!a->size)
		return (0);
	bin = a->end;
	a->end = a->end->prev;
	if (!a->end)
		a->start = NULL;
	else
		a->end->next = NULL;
	a->size--;
	chunk = a->chunks;
	while (chunk && chunk->next)
		chunk = chunk->next;
	if (chunk)
		chunk->size--;
	ps_isoldattribute(a, bin->nb, chunk);
	if (f == 1)
		free(bin);
	return (1);
}
