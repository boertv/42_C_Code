/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:10:02 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/20 11:33:21 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_error(t_stack *a, t_stack *b)
{
	while (ps_del_back(a, 1) || ps_del_back(b, 1))
		(void)a;
	while (ps_del_chunk(a) || ps_del_chunk(b))
		(void)a;
	ps_print_clear(a, b);
	write(2, "Error\n", 6);
	return (0);
}
