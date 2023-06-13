/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_manoeuvres.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:56:31 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/13 13:53:07 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pushes 'nb' from 'src' to 'dst' with the least amount of (r)rotates
// ignores chunks entirely
void	ps_fastest_push(t_stack *src, t_stack *dst, int nb, char csrc)
{
	t_dlilist	*list;
	size_t		i;

	list = src->start;
	i = 1;
	while (list && list->nb != nb)
	{
		i++;
		list = list->next;
	}
	if (list->nb != nb || (csrc != 'a' && csrc != 'b'))
		return ;
	if (i <= (src->size / 2 + 1))
	{
		while (--i)
			ps_rotate(src, csrc);
	}
	else
	{
		while (i++ <= src->size)
			ps_rrotate(src, csrc);
	}
	ps_push(src, dst, ((csrc == 'a') * 'b') + ((csrc == 'b') * 'a'));
}
