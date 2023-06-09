/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:47:20 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/30 17:28:29 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 1 if something was trimmed, else 0.
// compares 'el' and 'el->next'.
static int	ps_trim_superfluous(t_stack *s, t_dlilist *el)
{
	if (!el || !el->next)
		return (0);
	if ((el->nb == OP_PA && el->next->nb == OP_PB)
		|| (el->nb == OP_PB && el->next->nb == OP_PA)
		|| (el->nb == OP_RA && el->next->nb == OP_RRA)
		|| (el->nb == OP_RRA && el->next->nb == OP_RA)
		|| (el->nb == OP_RB && el->next->nb == OP_RRB)
		|| (el->nb == OP_RRB && el->next->nb == OP_RB))
	{
		ps_print_del(s, el->next);
		ps_print_del(s, el);
		return (1);
	}
	return (0);
}

// returns 1 if something was joined, else 0.
// compares 'el' and 'el->next'.
static int	ps_trim_doubles(t_stack *s, t_dlilist *el)
{
	if (!el || !el->next)
		return (0);
	if ((el->nb == OP_SA && el->next->nb == OP_SB)
		|| (el->nb == OP_SB && el->next->nb == OP_SA))
	{
		ps_print_del(s, el->next);
		el->nb = OP_SS;
		return (1);
	}
	else if ((el->nb == OP_RA && el->next->nb == OP_RB)
		|| (el->nb == OP_RB && el->next->nb == OP_RA))
	{
		ps_print_del(s, el->next);
		el->nb = OP_RR;
		return (1);
	}
	else if ((el->nb == OP_RRA && el->next->nb == OP_RRB)
		|| (el->nb == OP_RRB && el->next->nb == OP_RRA))
	{
		ps_print_del(s, el->next);
		el->nb = OP_RRR;
		return (1);
	}
	return (0);
}

void	ps_print_trim(t_stack *s)
{
	t_dlilist	*list;
	t_dlilist	*rear;

	if (!s->print_front || !*(s->print_front) || !(*(s->print_front))->next)
		return ;
	list = (*(s->print_front))->next;
	while (list && list->next)
	{
		rear = list->prev;
		while (ps_trim_superfluous(s, list))
		{
			list = rear;
			if (!rear->nb && rear->next)
				list = rear->next;
			rear = list->prev;
		}
		while (ps_trim_doubles(s, list))
		{
			list = rear;
			if (!rear->nb && rear->next)
				list = rear->next;
			rear = list->prev;
		}
		list = list->next;
	}
}

void	ps_print_compression(t_stack *s)
{
	ps_print_trim(s);
	ps_print_optimising(s);
	ps_print_trim(s);
}
