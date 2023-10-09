/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_updates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:54:08 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/09 16:12:14 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_upd_clbl(t_sl_data *data, int x, int y)
{
	int	exit_x;
	int	exit_y;

	data->clbls++;
	if (data->munetmr != SL_IMMUNITY)
		sl_print_clbl(data);
	if (data->clbls >= data->clblt)
	{
		if (!sl_search_map(data, EXIT_CLSD, &exit_x, &exit_y))
		{
			data->map[exit_y][exit_x] = EXIT_OPEN;
			if (data->munetmr != SL_IMMUNITY)
			{
				sl_print_midtext(data, "The exit opened!", -1, MSG_COL);
				data->msgtimer = 70;
				sl_print_tile(data, exit_x, exit_y, 0);
			}
		}
	}
	data->map[y][x] = CLBL_OLD;
	if (data->munetmr != SL_IMMUNITY && y > 0 && data->map[y - 1][x] == WALL)
		sl_print_tile(data, x, y - 1, 0);
	sl_grow_plr(data);
	return (0);
}

// returns 1 when the game ends
int	sl_upd_plmv(t_sl_data *data, int x, int y)
{
	(data->mvs)++;
	if (data->munetmr != SL_IMMUNITY || data->map[y][x] == EXIT_OPEN)
		sl_print_mvs(data);
	if (data->map[y][x] == EXIT_OPEN)
	{
		sl_victory_screen(data);
		return (1);
	}
	return (0);
}

// does the plr. for crs checks if new_dir_next_mv is on
// if new_dir_next_mv > 1 it returns 1
int	sl_upd_crdir(t_sl_data *data, int *x, int *y, char *dir)
{
	t_creature	*cr;

	if (x && y)
	{
		cr = sl_search_cr_xy(data, *x, *y);
		if (!cr)
			return (2);
		if (cr->new_dir_next_mv)
		{
			sl_cr_dir_next(data, cr);
			*dir = cr->dir[cr->dir_i];
			cr->new_dir_next_mv--;
		}
		if (cr->new_dir_next_mv)
		{
			cr->new_dir_next_mv = 0;
			return (1);
		}
		return (0);
	}
	data->plr[2] = ((*dir == DIR_UP) * (FACE_BACK))
		+ ((*dir == DIR_DOWN) * (FACE_FRONT))
		+ ((*dir == DIR_LEFT) * (FACE_LEFT))
		+ ((*dir == DIR_RIGHT) * (FACE_RIGHT));
	return (0);
}
