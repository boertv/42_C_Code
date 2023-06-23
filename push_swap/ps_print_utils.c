/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:09:22 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/23 16:31:07 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_initialise_print(t_stack *a, t_stack *b)
{
	t_dlilist	*runner;

	runner = ps_create_element(0);
	if (!runner)
		return (0);
	a->print_front = NULL;
	a->print_back = NULL;
	b->print_front = NULL;
	b->print_back = NULL;
	a->print_front = malloc(sizeof(t_dlilist *));
	a->print_back = malloc(sizeof(t_dlilist *));
	if ((!a->print_front || !a->print_back))
		return (0);
	*(a->print_front) = runner;
	*(a->print_back) = runner;
	b->print_front = a->print_front;
	b->print_back = a->print_back;
	return (1);
}

// returns 0 if el = NULL, else 1.
int	ps_print_add_back(t_stack *s, t_dlilist *el)
{
	if (!el)
		return (0);
	(*(s->print_back))->next = el;
	el->prev = (*(s->print_back));
	(*(s->print_back)) = el;
	return (1);
}

// clears the full list.
void	ps_print_clear(t_stack *s)
{
	t_dlilist	*bin;
	t_dlilist	*list;

	if (!s->print_front && !s->print_back)
		return ;
	if (s->print_front)
		list = *(s->print_front);
	else
		list = NULL;
	while (list)
	{
		bin = list;
		list = list->next;
		free(bin);
	}
	if (s->print_front)
		free (s->print_front);
	if (s->print_back)
		free (s->print_back);
	s->print_front = NULL;
	s->print_back = NULL;
}

// returns 0 if el = NULL, else 1.
int	ps_print_del(t_stack *s, t_dlilist *el)
{
	if (!el)
		return (0);
	if (el->prev)
		el->prev->next = el->next;
	else
		*(s->print_front) = el->next;
	if (el->next)
		el->next->prev = el->prev;
	else
		*(s->print_back) = el->prev;
	free(el);
	return (1);
}
