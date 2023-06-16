/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:18:52 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/16 18:29:51 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// UNFINISHED AF !!
// if 'a' then sort ascending.
int	ps_sort_three_chunk(t_stack *s, char c, char a)
{
	int	i;

	i = 0;
	if (!a)
	{
		ps_sort_three_chunk_a();
		return (1);
	}
	if (s->start->nb == s->chunks->max)
	{
		i++;
		if (!ps_rotate(s, c))
			return (0);
	}
}
