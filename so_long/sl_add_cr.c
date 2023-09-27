/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_add_cr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:17:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/27 17:22:41 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns 1 if malloc failed
int	sl_add_cr(t_sl_data *data, char cr, int x, int y)
{
	t_creature	*content;
	t_list		*new;

	content = malloc (sizeof(t_creature));
	if (!content)
		return (1);
	new = ft_lstnew((void *) content);
	if (!new)
	{
		free(content);
		return (1);
	}
	((t_creature *) new->content)->type = cr;
	((t_creature *) new->content)->cd[0] = x;
	((t_creature *) new->content)->cd[1] = y;
	((t_creature *) new->content)->dir_i = 0;
	((t_creature *) new->content)->anim = NULL;
	if (cr == KNIGHT)
		((t_creature *) new->content)->dir = DIR_K;
	if (cr == WIZARD)
		((t_creature *) new->content)->dir = DIR_W;
	ft_lstadd_back(data->crs, new);
	return (0);
}
