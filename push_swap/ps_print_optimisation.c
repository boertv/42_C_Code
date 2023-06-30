/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_optimisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:29:53 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/30 16:45:52 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 1 if something was replaced, else 0.
static int	ps_replace_rapbrra_sapb(t_stack *s, t_dlilist *el)
{
	t_dlilist	*bin;

	bin = el->next;
	if (el->nb == OP_RA)
	{
		if (bin && bin->nb == OP_PB)
			bin = bin->next;
		else
			return (0);
	}
	else if (el->nb == OP_RB)
	{
		if (bin && bin->nb == OP_PA)
			bin = bin->next;
		else
			return (0);
	}
	if (bin && bin->nb == el->nb + 2)
	{
		ps_print_del(s, bin);
		el->nb -= 4;
		return (1);
	}
	return (0);
}

// returns 1 if something was replaced, else 0.
static int	ps_replace_rrasapb_pbrra(t_stack *s, t_dlilist *el)
{
	t_dlilist	*bin;

	bin = el->next;
	if (bin && bin->next && bin->nb == el->nb - 6)
		bin = bin->next;
	else
		return (0);
	if (el->nb == OP_RRA)
		if (bin && bin->nb != OP_PB)
			return (0);
	if (el->nb == OP_RRB)
		if (bin && bin->nb != OP_PA)
			return (0);
	ps_print_del(s, bin);
	el->next->nb += 6;
	el->nb = ((el->nb == OP_RRA) * OP_PB) + ((el->nb == OP_RRB) * OP_PA);
	return (1);
}

// returns 1 if something was replaced, else 0.
// this doesn't seem to ever come into play... ever
static int	ps_replace_sarbrbsb_rbrbss(t_stack *s, t_dlilist *el)
{
	t_dlilist	*list;

	list = el->next;
	if (!list)
		return (0);
	while ((el->nb == OP_SA && (list->nb == OP_RB || list->nb == OP_RRB))
		|| (el->nb == OP_SB && (list->nb == OP_RA || list->nb == OP_RRA)))
	{
		list = list->next;
		if (!list)
			break ;
	}
	if (list && ((el->nb == OP_SA && list->nb == OP_SB)
			|| (el->nb == OP_SB && list->nb == OP_SA)))
	{
		ps_print_del(s, el);
		list->nb = OP_SS;
		return (1);
	}
	return (0);
}

void	ps_print_optimising(t_stack *s)
{
	t_dlilist	*el;

	if (!s->print_front)
		return ;
	el = (*(s->print_front));
	while (el)
	{
		if (el->nb == OP_RA || el->nb == OP_RB)
			if (ps_replace_rapbrra_sapb(s, el))
				el = el->prev->prev;
		if (el && (el->nb == OP_RRA || el->nb == OP_RRB))
			if (ps_replace_rrasapb_pbrra(s, el))
				el = el->prev->prev;
		if (el && el->next && (el->next->nb == OP_SA || el->next->nb == OP_SB))
			if (ps_replace_sarbrbsb_rbrbss(s, el->next))
				el = el->prev;
		if (el)
			el = el->next;
		else
			el = (*(s->print_front));
	}
}
