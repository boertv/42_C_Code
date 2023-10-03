/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:25:32 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/03 14:57:31 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_bounce(t_sl_data *data, t_creature *cr)
{
	t_creature	*bounced_cr;

	if (cr->dir[cr->dir_i] == DIR_RIGHT)
		bounced_cr = sl_search_cr_xy(data, cr->cd[0] + 1, cr->cd[1]);
	else if (cr->dir[cr->dir_i] == DIR_LEFT)
		bounced_cr = sl_search_cr_xy(data, cr->cd[0] - 1, cr->cd[1]);
	else if (cr->dir[cr->dir_i] == DIR_UP)
		bounced_cr = sl_search_cr_xy(data, cr->cd[0], cr->cd[1] - 1);
	else if (cr->dir[cr->dir_i] == DIR_DOWN)
		bounced_cr = sl_search_cr_xy(data, cr->cd[0], cr->cd[1] + 1);
	else
		return ;
	if (!bounced_cr)
		return ;
	bounced_cr->new_dir_next_mv = 1;
	if (cr->dir[cr->dir_i] == DIR_RIGHT)
		bounced_cr->new_dir_next_mv = 2;
}

static void	sl_start_anim(t_sl_data *data, t_creature *cr)
{
	if (cr->type == KNIGHT)
	{
		if (cr->dir[cr->dir_i] == DIR_LEFT)
		{
			cr->frame = *data->am->k_mv_l;
			cr->offset = OFF_K_START;
		}
		else
		{
			cr->frame = *data->am->k_mv_r;
			cr->offset = OFF_K_START * -1;
		}
	}
	sl_print_am_frame(data, cr);
}

// checks if cr should be advanced and does that
void	sl_cr_advance_tile(t_sl_data *data, t_creature *cr)
{
	int	oldx;
	int	oldy;

	if (cr->offset > -30 && 30 > cr->offset)
	{
		if (data->mask_cr[cr->cd[1]][cr->cd[0]] == cr->type)
			return ;
		data->mask_cr[cr->cd[1]][cr->cd[0]] = cr->type;
		oldx = cr->cd[0] - (cr->dir[cr->dir_i] == DIR_RIGHT)
			+ (cr->dir[cr->dir_i] == DIR_LEFT);
		oldy = cr->cd[1] - (cr->dir[cr->dir_i] == DIR_DOWN)
			+ (cr->dir[cr->dir_i] == DIR_UP);
		data->mask_cr[oldy][oldx] = EMPTY;
	}
}

static int	sl_moving_knight(t_sl_data *data, t_creature *cr)
{
	int	check;

	check = sl_move_cr(data, &cr->cd[0], &cr->cd[1], cr->dir[cr->dir_i]);
	if (!check)
		sl_start_anim(data, cr);
	if (check == 2)
		sl_bounce(data, cr);
	if (check)
	{
		if (check != 3)
			sl_cr_dir_next(data, cr);
		sl_print_tile(data, cr->cd[0], cr->cd[1], 0);
	}
	return (1);
}

void	sl_move_crs(t_sl_data *data)
{
	t_list	*lst;

	lst = *(data->crs);
	while (lst)
	{
		if (((t_creature *)(lst->content))->type == KNIGHT)
			sl_moving_knight(data, lst->content);
		lst = lst->next;
	}
}
