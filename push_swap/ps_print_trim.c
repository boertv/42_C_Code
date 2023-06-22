/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:47:20 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/22 17:51:39 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 1 if something was trimmed, else 0.
// compares 'el' and 'el->next'.
static int	ps_trim_superfluous(t_stack *a, t_dlilist *el)
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
		ps_print_del(a, el->next);
		ps_print_del(a, el);
		return (1);
	}
	return (0);
}

// returns 1 if something was joined, else 0.
// compares 'el' and 'el->next'.
static int	ps_trim_doubles(t_stack *a, t_dlilist *el)
{
	if (!el || !el->next)
		return (0);
	if ((el->nb == OP_SA && el->next->nb == OP_SB)
		|| (el->nb == OP_SB && el->next->nb == OP_SA))
	{
		ps_print_del(a, el->next);
		el->nb = OP_SS;
		return (1);
	}
	else if ((el->nb == OP_RA && el->next->nb == OP_RB)
		|| (el->nb == OP_RB && el->next->nb == OP_RA))
	{
		ps_print_del(a, el->next);
		el->nb = OP_RR;
		return (1);
	}
	else if ((el->nb == OP_RRA && el->next->nb == OP_RRB)
		|| (el->nb == OP_RRB && el->next->nb == OP_RRA))
	{
		ps_print_del(a, el->next);
		el->nb = OP_RRR;
		return (1);
	}
	return (0);
}

void	ps_print_trim(t_stack *a)
{
	t_dlilist	*list;
	t_dlilist	*rear;

	if (!a->print_front || !*(a->print_front) || !(*(a->print_front))->next)
		return ;
	list = (*(a->print_front))->next;
	while (list->next)
	{
		rear = list->prev;
		while (ps_trim_superfluous(a, list))
		{
			list = rear;
			if (!rear->nb)
				list = rear->next;
			rear = list->prev;
		}
		while (ps_trim_doubles(a, list))
		{
			list = rear;
			if (!rear->nb)
				list = rear->next;
			rear = list->prev;
		}
		list = list->next;
	}
}

void	ps_print_compression(t_stack *a)
{
	ps_print_trim(a);
	ps_print_optimising(a);
	ps_print_trim(a);
}
