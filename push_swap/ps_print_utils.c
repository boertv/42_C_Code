/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:09:22 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/21 16:26:13 by bvercaem         ###   ########.fr       */
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
int	ps_print_add_back(t_stack *a, t_dlilist *el)
{
	if (!el)
		return (0);
	(*(a->print_back))->next = el;
	el->prev = (*(a->print_back));
	(*(a->print_back)) = el;
	return (1);
}

// clears the full list.
void	ps_print_clear(t_stack *a)
{
	t_dlilist	*bin;
	t_dlilist	*list;

	if (!a->print_front && !a->print_back)
		return ;
	if (a->print_front)
		list = *(a->print_front);
	else
		list = NULL;
	while (list)
	{
		bin = list;
		list = list->next;
		free(bin);
	}
	if (a->print_front)
		free (a->print_front);
	if (a->print_back)
		free (a->print_back);
	a->print_front = NULL;
	a->print_back = NULL;
}

// returns 0 if el = NULL, else 1.
int	ps_print_del(t_stack *a, t_dlilist *el)
{
	if (!el)
		return (0);
	if (el->prev)
		el->prev->next = el->next;
	else
		*(a->print_front) = el->next;
	if (el->next)
		el->next->prev = el->prev;
	else
		*(a->print_back) = el->prev;
	free(el);
	return (1);
}
