/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:26:09 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/16 20:07:13 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 if command was unrecognized, else 1.
static int	ps_print_hub(t_dlilist *list)
{
	if (list->nb == OP_SA)
		ft_printf("sa\n");
	else if (list->nb == OP_SB)
		ft_printf("sb\n");
	else if (list->nb == OP_PA)
		ft_printf("pa\n");
	else if (list->nb == OP_PB)
		ft_printf("pb\n");
	else if (list->nb == OP_RA)
		ft_printf("ra\n");
	else if (list->nb == OP_RB)
		ft_printf("rb\n");
	else if (list->nb == OP_RRA)
		ft_printf("rra\n");
	else if (list->nb == OP_RRB)
		ft_printf("rrb\n");
	else if (list->nb == OP_SS)
		ft_printf("ss\n");
	else if (list->nb == OP_RR)
		ft_printf("rr\n");
	else if (list->nb == OP_RRR)
		ft_printf("rrr\n");
	else
		return (0);
	return (1);
}

void	ps_print_ops(t_stack *a)
{
	t_dlilist	*list;

	list = (*a->print_front)->next;
	while (list)
	{
		if (!ps_print_hub(list))
			{
				write(2, "Error\n", 6);
				return ;
			}
		list = list->next;
	}
}
