/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_cr_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:17:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/03 16:64:44 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_print_am_frame(t_sl_data *data, t_creature *cr)
{
	int	w;
	int	h;

	w = sl_cv_cdpx(cr->cd[0], 'x', cr->offset);
	h = sl_cv_cdpx(cr->cd[1], 'y', cr->offset);
	sl_print_tile(data, cr->cd[0], cr->cd[1], 0);
	sl_print_tile(data, cr->cd[0] + (cr->dir[cr->dir_i] == DIR_LEFT)
		- (cr->dir[cr->dir_i] == DIR_RIGHT), cr->cd[1]
		+ (cr->dir[cr->dir_i] == DIR_UP) - (cr->dir[cr->dir_i] == DIR_DOWN), 0);
	mlx_put_image_to_window(data->mlx, data->win, cr->frame->content, w, h);
}

// prints the next frame in the anim and increments or ends it
void	sl_advance_am(t_sl_data *data, t_creature *cr)
{
	if (!cr->frame)
		return ;
	cr->frame = cr->frame->next;
	if (!cr->frame)
	{
		cr->offset = 0;
		sl_cr_advance_tile(data, cr);
		sl_print_tile(data, cr->cd[0], cr->cd[1], 0);
		sl_print_tile(data, cr->cd[0] + (cr->dir[cr->dir_i] == DIR_LEFT)
			- (cr->dir[cr->dir_i] == DIR_RIGHT), cr->cd[1]
			+ (cr->dir[cr->dir_i] == DIR_UP)
			- (cr->dir[cr->dir_i] == DIR_DOWN), 0);
		return ;
	}
	if (cr->type == KNIGHT)
	{
		if (cr->dir[cr->dir_i] == DIR_LEFT)
			cr->offset -= OFF_K_INC;
		else
			cr->offset += OFF_K_INC;
	}
	sl_cr_advance_tile(data, cr);
	sl_print_am_frame(data, cr);
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
