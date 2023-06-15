/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:18:52 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/15 17:38:52 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if 'a' then sort ascending.
void	ps_sort_three_chunk(t_stack *s, char c, char a)
{
	int	i;

	i = 0;
	if (!a)
	{
		ps_sort_three_chunk_a();
		return ;
	}
	if (s->start->nb == s->chunks->max)
	{
		i++;
		ps_rotate(s, c);
	}
}
