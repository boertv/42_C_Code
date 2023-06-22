/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_optimisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:29:53 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/22 18:13:25 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 1 if something was replaced, else 0.
static int	ps_replace_rapbrra_sapb(t_stack *a, t_dlilist *el)
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
		ps_print_del(a, bin);
		el->nb -= 4;
		return (1);
	}
	return (0);
}

// returns 1 if something was replaced, else 0.
static int	ps_replace_rrasapb_pbrra(t_stack *a, t_dlilist *el)
{
	t_dlilist	*bin;

	bin = el->next;
	if (bin && bin->nb == el->nb - 6)
		bin = bin->next;
	else
		return (0);
	if (el->nb == OP_RRA)
		if (bin && bin->nb != OP_PB)
			return (0);
	if (el->nb == OP_RRB)
		if (bin && bin->nb != OP_PA)
			return (0);
	ps_print_del(a, bin);
	el->next->nb += 6;
	el->nb = ((el->nb == OP_RRA) * OP_PB) + ((el->nb == OP_RRB) * OP_PA);
	return (1);
}

void	ps_print_optimising(t_stack *a)
{
	t_dlilist	*el;

	if (!a->print_front)
		return ;
	el = (*(a->print_front));
	while (el)
	{
		if (el->nb == OP_RA || el->nb == OP_RB)
			if (ps_replace_rapbrra_sapb(a, el))
				el = el->prev->prev;
		if (el->nb == OP_RRA || el->nb == OP_RRB)
			if (ps_replace_rrasapb_pbrra(a, el))
				el = el->prev->prev;
		if (el)
			el = el->next;
		else
			el = (*(a->print_front));
	}
}
