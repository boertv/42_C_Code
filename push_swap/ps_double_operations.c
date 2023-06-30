/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_double_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:58:25 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/30 12:33:08 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 if a create_element failed, else 1.
int	ps_ss(t_stack *a, t_stack *b, short p)
{
	if (p && !ps_print_add_back(a, ps_create_element(OP_SS)))
		return (0);
	if (!ps_swap(a, NULL, 0) || !ps_swap(b, NULL, 0))
		return (0);
	return (1);
}

// returns 0 if a create_element failed, else 1.
int	ps_rr(t_stack *a, t_stack *b, short p)
{
	if (p && !ps_print_add_back(a, ps_create_element(OP_RR)))
		return (0);
	if (!ps_rotate(a, 0) || !ps_rotate(b, 0))
		return (0);
	return (1);
}

// returns 0 if a create_element failed, else 1.
int	ps_rrr(t_stack *a, t_stack *b, short p)
{
	if (p && !ps_print_add_back(a, ps_create_element(OP_RRR)))
		return (0);
	if (!ps_rrotate(a, 0) || !ps_rrotate(b, 0))
		return (0);
	return (1);
}
