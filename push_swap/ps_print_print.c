/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:26:09 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/20 17:52:41 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 if command was unrecognized, else 1.
int	ps_print_hub(t_dlilist *list)
{
// MAKE STATIC AGAIN
	if (list->nb == OP_SA)
		ft_printf("sa");
	else if (list->nb == OP_SB)
		ft_printf("sb");
	else if (list->nb == OP_PA)
		ft_printf("pa");
	else if (list->nb == OP_PB)
		ft_printf("pb");
	else if (list->nb == OP_RA)
		ft_printf("ra");
	else if (list->nb == OP_RB)
		ft_printf("rb");
	else if (list->nb == OP_RRA)
		ft_printf("rra");
	else if (list->nb == OP_RRB)
		ft_printf("rrb");
	else if (list->nb == OP_SS)
		ft_printf("ss");
	else if (list->nb == OP_RR)
		ft_printf("rr");
	else if (list->nb == OP_RRR)
		ft_printf("rrr");
	else
		return (0);
	return (1);
}

void	ps_print_ops(t_stack *a)
{
	t_dlilist	*list;

	if (!a->print_front || !*(a->print_front))
		return ;
	list = (*(a->print_front))->next;
	while (list)
	{
		if (!ps_print_hub(list))
		{
			write(2, "Error\n", 6);
			return ;
		}
		ft_printf("\n");
		list = list->next;
	}
}
