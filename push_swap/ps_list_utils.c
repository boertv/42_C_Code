/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:09:33 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/07 15:19:35 by bvercaem         ###   ########.fr       */
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
	if (!a->start)
		a->end = el;
	else
		a->start->prev = el;
	a->start = el;
	a->size++;
	return (1);
}

// returns 0 if el == NULL, else 1
int	ps_add_back(t_stack *a, t_dlilist *el)
{
	if (!el)
		return (0);
	el->next = NULL;
	el->prev = a->end;
	if (!a->end)
		a->start = el;
	else
		a->end->next = el;
	a->end = el;
	a->size++;
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
	if (f == 1)
		free(bin);
	a->size--;
	return (1);
}

// returns 0 if list is empty, else 1
// if f == 1 the data is freed
int	ps_del_back(t_stack *a, short f)
{
	t_dlilist	*bin;

	if (!a->size)
		return (0);
	bin = a->end;
	a->end = a->end->prev;
	if (!a->end)
		a->start = NULL;
	else
		a->end->next = NULL;
	if (f == 1)
		free(bin);
	a->size--;
	return (1);
}
