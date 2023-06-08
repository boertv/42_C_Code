/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_manoeuvres.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:56:31 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/08 19:20:08 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// THIS FUNCTION NO WORKIE!!
void	ps_fastest_push(t_stack *src, t_stack *dst, int nb, char csrc)
{
	t_dlilist	*list;
	size_t			i;

	list = src->start;
	i = 1;
	while (list && list->nb != nb)
	{
		i++;
		list = list->next;
	}
	if (list->nb != nb || (csrc != 'a' && csrc != 'b'))
		return ;
	if (i <= (src->size / 2))
	{
		while (--i)
			ps_rotate(src, csrc);
	}
	else
	{
		while (i--)
			ps_rrotate(src, csrc);
	}
	ps_push(src, dst, ((csrc == 'a') * 'b') + ((csrc == 'b') * 'a'));
}
