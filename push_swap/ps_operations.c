/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:50:40 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/05 17:43:59 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_stack a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->array[0];
	a->array[0] = a->array[1];
	a->array[1] = temp;
}

void	ps_push(t_stack src, t_stack dst)
{
	if (!src->size)
		return ;
	dst->size++;
	ps_shiftdown(dst);
	dst->array[0] = src->array[0];
	ps_shiftup(src);
	src->size--;
}

void	ps_rotate(t_stack a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->array[0];
	ps_shiftup(a);
	a->array[a->size - 1] = temp;
}

void	ps_rrotate(t_stack a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->array[a->size - 1];
	ps_shiftdown(a);
	a->array[0] = temp;
}
