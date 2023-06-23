/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:50:40 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/23 15:44:51 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 if create_element failed, else 1.
int	ps_swap(t_stack *a, t_stack *o, char c)
{
	if (o && ((c == 'a' && o->size > 1 && o->start->nb < o->start->next->nb)
		|| (c == 'b' && o->size > 1 && o->start->nb > o->start->next->nb)))
		return (ps_ss(a, o));
	if (c == 'a')
		if (!ps_print_add_back(a, ps_create_element(OP_SA)))
			return (0);
	if (c == 'b')
		if (!ps_print_add_back(a, ps_create_element(OP_SB)))
			return (0);
	if (a->size < 2)
		return (1);
	if (a->start->next->next)
		a->start->next->next->prev = a->start;
	a->start->prev = a->start->next;
	a->start->next = a->start->next->next;
	a->start->prev->next = a->start;
	a->start = a->start->prev;
	a->start->prev = NULL;
	if (a->size == 2)
		a->end = a->start->next;
	return (1);
}

// returns 0 if create_element failed, else 1.
int	ps_push(t_stack *src, t_stack *dst, char cdst)
{
	t_dlilist	*temp;

	if (!src->start)
		return (1);
	if (cdst == 'a')
		if (!ps_print_add_back(src, ps_create_element(OP_PA)))
			return (0);
	if (cdst == 'b')
		if (!ps_print_add_back(src, ps_create_element(OP_PB)))
			return (0);
	temp = src->start;
	ps_del_front(src, 0);
	ps_add_front(dst, temp);
	return (1);
}

// returns 0 if create_element failed, else 1.
int	ps_rotate(t_stack *a, char c)
{
	t_dlilist	*temp;

	if (!a->start)
		return (1);
	if (c == 'a')
		if (!ps_print_add_back(a, ps_create_element(OP_RA)))
			return (0);
	if (c == 'b')
		if (!ps_print_add_back(a, ps_create_element(OP_RB)))
			return (0);
	temp = a->start;
	ps_del_front(a, 0);
	ps_add_back(a, temp);
	return (1);
}

// returns 0 if create_element failed, else 1.
int	ps_rrotate(t_stack *a, char c)
{
	t_dlilist	*temp;

	if (!a->end)
		return (1);
	if (c == 'a')
		if (!ps_print_add_back(a, ps_create_element(OP_RRA)))
			return (0);
	if (c == 'b')
		if (!ps_print_add_back(a, ps_create_element(OP_RRB)))
			return (0);
	temp = a->end;
	ps_del_back(a, 0);
	ps_add_front(a, temp);
	return (1);
}
