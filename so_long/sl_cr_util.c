/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_cr_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:17:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/05 17:34:55 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_clear_crs(t_sl_data *data)
{
	if (!data->crs)
		return ;
	ft_lstclear(data->crs, free);
	free(data->crs);
	data->crs = NULL;
}

void	sl_cr_dir_next(t_sl_data *data, t_creature *cr)
{
	cr->frame = NULL;
	cr->offset = 0;
	sl_cr_advance_tile(data, cr);
	cr->dir_i++;
	if (!cr->dir[cr->dir_i])
		cr->dir_i = 0;
}

// returns NULL if no cr found
t_creature	*sl_search_cr_xy(t_sl_data *data, int x, int y)
{
	t_list	*lst;

	lst = *(data->crs);
	while (lst && (((t_creature *) lst->content)->cd[0] != x
			|| ((t_creature *) lst->content)->cd[1] != y))
		lst = lst->next;
	if (!lst)
		return (NULL);
	return ((t_creature *) lst->content);
}

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
	((t_creature *) new->content)->new_dir_next_mv = 0;
	((t_creature *) new->content)->offset = 0;
	((t_creature *) new->content)->frame = NULL;
	if (cr == KNIGHT)
		((t_creature *) new->content)->dir = DIR_K;
	if (cr == WIZARD)
		((t_creature *) new->content)->dir = DIR_W;
	ft_lstadd_back(data->crs, new);
	return (0);
}
