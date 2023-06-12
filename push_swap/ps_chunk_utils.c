/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:36:30 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/12 17:00:03 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_add_chunk(t_chunk *chunks, void *content)
{
	t_chunk	*new;

	if (!content)
		return (0);
	new = ft_lstnew(content);
	if (!new)
	{
		free(content);
		return (0);
	}
	ft_lstadd_front(&chunks, new);
	return (1);
}
