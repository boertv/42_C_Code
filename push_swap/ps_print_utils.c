/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:09:22 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/16 19:24:01 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_initialise_print(t_stack *a, t_stack *b)
{
	t_dlilist	*runner;

	runner = ps_create_element(0);
	if (!runner)
		return (0);
	a->print_front = &runner;
	a->print_back = &runner;
	b->print_front = a->print_front;
	b->print_back = a->print_back;
	return (1);
}

// returns 0 if el = NULL, else 1.
int	ps_print_add_back(t_stack *a, t_dlilist *el)
{
	if (!el)
		return (0);
	(*a->print_back)->next = el;
	el->prev = (*a->print_back);
	(*a->print_back) = el;
	return (1);
}

// clears the full list.
void	ps_print_clear(t_stack *a)
{
	t_dlilist	*bin;

	while ((*a->print_front))
	{
		bin = (*a->print_front);
		a->print_front = &((*a->print_front)->next);
		free(bin);
	}
}

// returns 0 if el = NULL, else 1.
int	ps_print_del(t_dlilist *el)
{
	if (!el)
		return (0);
	if (el->prev)
		el->prev->next = el->next;
	if (el->next)
		el->next->prev = el->prev;
	free(el);
	return (1);
}

// add function to trim the list.
