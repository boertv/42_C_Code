/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:50:40 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/13 14:38:01 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ignores chunks
void	ps_swap(t_stack *a, char c)
{
	if (c != '0')
		ft_printf("s%c\n", c);
	if (a->size < 2)
		return ;
	if (a->start->next->next)
		a->start->next->next->prev = a->start;
	a->start->prev = a->start->next;
	a->start->next = a->start->next->next;
	a->start->prev->next = a->start;
	a->start = a->start->prev;
	a->start->prev = NULL;
	if (a->size == 2)
		a->end = a->start->next;
}

// increments chunk sizes if at least dst->chunks exists.
void	ps_push(t_stack *src, t_stack *dst, char c)
{
	t_dlilist	*temp;

	if (c != '0')
		ft_printf("p%c\n", c);
	temp = src->start;
	if (src->size && dst->chunks)
	{
		if (src->chunks && src->chunks->size)
			src->chunks->size--;
		dst->chunks->size++;
	}
	ps_del_front(src, 0);
	ps_add_front(dst, temp);
}

// ignores chunks
void	ps_rotate(t_stack *a, char c)
{
	t_dlilist	*temp;

	if (c != '0')
		ft_printf("r%c\n", c);
	temp = a->start;
	ps_del_front(a, 0);
	ps_add_back(a, temp);
}

// ignores chunks
void	ps_rrotate(t_stack *a, char c)
{
	t_dlilist	*temp;

	if (c != '0')
		ft_printf("rr%c\n", c);
	temp = a->end;
	ps_del_back(a, 0);
	ps_add_front(a, temp);
}
