/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_double_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:58:25 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/07 16:09:04 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ss(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	ps_swap(a, '0');
	ps_swap(b, '0');
}

void	ps_rr(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	ps_rotate(a, '0');
	ps_rotate(b, '0');
}

void	ps_rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	ps_rrotate(a, '0');
	ps_rrotate(b, '0');
}
