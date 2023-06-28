/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:50:40 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/28 17:29:40 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 if create_element failed, else 1.
// if p = 0 it doesn't print OP_SA or OP_SB.
int	ps_swap(t_stack *s, t_stack *o, short p)
{
	if (p && o && ((s->a && o->size > 1 && o->start->nb < o->start->next->nb)
			|| (!s->a && o->size > 1 && o->start->nb > o->start->next->nb)))
		return (ps_ss(s, o));
	if (p && s->a)
		if (!ps_print_add_back(s, ps_create_element(OP_SA)))
			return (0);
	if (p && !s->a)
		if (!ps_print_add_back(s, ps_create_element(OP_SB)))
			return (0);
	if (s->size < 2)
		return (1);
	if (s->start->next->next)
		s->start->next->next->prev = s->start;
	s->start->prev = s->start->next;
	s->start->next = s->start->next->next;
	s->start->prev->next = s->start;
	s->start = s->start->prev;
	s->start->prev = NULL;
	if (s->size == 2)
		s->end = s->start->next;
	return (1);
}

// returns 0 if create_element failed, else 1.
int	ps_push(t_stack *src, t_stack *dst)
{
	t_dlilist	*temp;

	if (!src->start)
		return (1);
	if ((dst->a && (*(src->print_back))->nb == OP_PB)
		|| (!dst->a && (*(src->print_back))->nb == OP_PA))
		ps_print_del(src, (*(src->print_back)));
	else if (dst->a)
	{
		if (!ps_print_add_back(src, ps_create_element(OP_PA)))
			return (0);
	}
	else if (!dst->a)
		if (!ps_print_add_back(src, ps_create_element(OP_PB)))
			return (0);
	temp = src->start;
	ps_del_front(src, 0);
	ps_add_front(dst, temp);
	return (1);
}

// returns 0 if create_element failed, else 1.
// if p = 0 it doesn't print OP_RA or OP_RB.
int	ps_rotate(t_stack *s, short p)
{
	t_dlilist	*temp;

	if (!s->start)
		return (1);
	if (p && ((s->a && (*(s->print_back))->nb == OP_RRA)
			|| (!s->a && (*(s->print_back))->nb == OP_RRB)))
	{
		ps_print_del(s, (*(s->print_back)));
		p = 0;
	}
	if (p && s->a)
		if (!ps_print_add_back(s, ps_create_element(OP_RA)))
			return (0);
	if (p && !s->a)
		if (!ps_print_add_back(s, ps_create_element(OP_RB)))
			return (0);
	temp = s->start;
	ps_del_front(s, 0);
	ps_add_back(s, temp);
	return (1);
}

// returns 0 if create_element failed, else 1.
// if p = 0 it doesn't print OP_RRA or OP_RRB.
int	ps_rrotate(t_stack *s, short p)
{
	t_dlilist	*temp;

	if (!s->end)
		return (1);
	if (p && ((s->a && (*(s->print_back))->nb == OP_RA)
			|| (!s->a && (*(s->print_back))->nb == OP_RB)))
	{
		ps_print_del(s, (*(s->print_back)));
		p = 0;
	}
	if (p && s->a)
		if (!ps_print_add_back(s, ps_create_element(OP_RRA)))
			return (0);
	if (p && !s->a)
		if (!ps_print_add_back(s, ps_create_element(OP_RRB)))
			return (0);
	temp = s->end;
	ps_del_back(s, 0);
	ps_add_front(s, temp);
	return (1);
}
