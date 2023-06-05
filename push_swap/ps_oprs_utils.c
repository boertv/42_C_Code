/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_oprs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:00:17 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/05 17:44:03 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// overwrites the top value.
void	ps_shiftup(t_stack a)
{
	size_t	i;

	i = 1;
	while (i < a->size)
	{
		a->array[i - 1] = a->array[i];
		i++;
	}
}

// overwrites the bottom value.
void	ps_shiftdown(t_stack a)
{
	size_t	i;

	i = a->size;
	while (i > 1)
	{
		a->array[i - 1] = a->array[i - 2];
		i--;
	}
}
