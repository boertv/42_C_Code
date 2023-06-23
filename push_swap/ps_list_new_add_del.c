/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_new_add_del.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:09:33 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/23 16:28:52 by bvercaem         ###   ########.fr       */
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
int	ps_add_front(t_stack *s, t_dlilist *el)
{
	if (!el)
		return (0);
	el->prev = NULL;
	el->next = s->start;
	s->size++;
	if (s->chunks && !s->chunks->size)
		ps_addnewattribute(s, el->nb, s->chunks);
	if (s->chunks)
		s->chunks->size++;
	if (!s->start)
	{
		s->end = el;
		ps_addnewattribute(s, el->nb, NULL);
	}
	else
	{
		s->start->prev = el;
		ps_isnewattribute(s, el->nb, s->chunks);
	}
	s->start = el;
	return (1);
}

// returns 0 if el == NULL, else 1
int	ps_add_back(t_stack *s, t_dlilist *el)
{
	t_chunk	*chunk;

	if (!el)
		return (0);
	el->next = NULL;
	el->prev = s->end;
	s->size++;
	chunk = ps_get_last_chunk(s->chunks);
	if (chunk && !chunk->size)
		ps_addnewattribute(s, el->nb, chunk);
	if (chunk)
		chunk->size++;
	if (!s->end)
	{
		s->start = el;
		ps_addnewattribute(s, el->nb, NULL);
	}
	else
	{
		s->end->next = el;
		ps_isnewattribute(s, el->nb, chunk);
	}
	s->end = el;
	return (1);
}

// returns 0 if list is empty, else 1
// if f == 1 the data is freed
int	ps_del_front(t_stack *s, short f)
{
	t_dlilist	*bin;

	if (!s->size)
		return (0);
	bin = s->start;
	s->start = s->start->next;
	if (!s->start)
		s->end = NULL;
	else
		s->start->prev = NULL;
	s->size--;
	if (s->chunks)
		s->chunks->size--;
	ps_isoldattribute(s, bin->nb, s->chunks);
	if (f == 1)
		free(bin);
	return (1);
}

// returns 0 if list is empty, else 1
// if f == 1 the data is freed
int	ps_del_back(t_stack *s, short f)
{
	t_dlilist	*bin;
	t_chunk		*chunk;

	if (!s->size)
		return (0);
	bin = s->end;
	s->end = s->end->prev;
	if (!s->end)
		s->start = NULL;
	else
		s->end->next = NULL;
	s->size--;
	chunk = ps_get_last_chunk(s->chunks);
	if (chunk)
		chunk->size--;
	ps_isoldattribute(s, bin->nb, chunk);
	if (f == 1)
		free(bin);
	return (1);
}
