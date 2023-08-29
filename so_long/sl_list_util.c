/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_list_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:46:46 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/29 18:58:02 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_solv_init(t_sl_slv *slv, t_sl_data *data)
{
	slv->col = data->clbls;
	slv->exi = 1;
	slv->old = NULL;
	slv->new = NULL;
}

// prints error msg if needed
t_sl_list	*sl_list_create(int x, int y)
{
	t_sl_list	*list;

	list = malloc(sizeof(t_sl_list));
	if (!list)
	{
		perror("list malloc: ");
		return (NULL);
	}
	list->next = NULL;
	list->prev = NULL;
	list->x = x;
	list->y = y;
	return (list);
}

// returns 1 if new == NULL
// updates *last
int	sl_list_addback(t_sl_list **last, t_sl_list *new)
{
	if (!new)
		return (1);
	if ((*last))
	{
		(*last)->next = new;
		new->prev = (*last);
	}
	(*last) = new;
	return (0);
}

// clears and returns NULL
t_sl_list	*sl_list_clear(t_sl_list *last)
{
	t_sl_list	*bin;

	while (last)
	{
		bin = last;
		last = last->prev;
		free(bin);
	}
	return (NULL);
}

// returns 1 if x-y combination exists, else 0
int	sl_list_search(t_sl_list *last, int x, int y)
{
	while (last)
	{
		if (last->x == x && last->y == y)
			return (1);
		last = last->prev;
	}
	return (0);
}
