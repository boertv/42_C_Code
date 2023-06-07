/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:50:40 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/07 15:21:59 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_stack *a)
{
	if (a->size < 2)
		return ;
	if (a->start->next->next)
		a->start->next->next->prev = a->start;
	a->start->prev = a->start->next;
	a->start->next = a->start->next->next;
	a->start->prev->next = a->start;
	a->start = a->start->prev;
	a->start->prev = NULL;
}

void	ps_push(t_stack *src, t_stack *dst)
{
	t_dlilist	*temp;

	temp = src->start;
	ps_del_front(src, 0);
	ps_add_front(dst, temp);
}

void	ps_rotate(t_stack *a)
{
	t_dlilist	*temp;

	temp = a->start;
	ps_del_front(a, 0);
	ps_add_back(a, temp);
}

void	ps_rrotate(t_stack *a)
{
	t_dlilist	*temp;

	temp = a->end;
	ps_del_back(a, 0);
	ps_add_front(a, temp);
}
