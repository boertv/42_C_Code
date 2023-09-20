/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_updates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:54:08 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/20 17:52:28 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_upd_clbl(t_sl_data *data, int x, int y)
{
	int	exit_x;
	int	exit_y;

	data->clbls++;
	sl_print_clbl(data);
	if (data->clbls >= data->clblt)
	{
		if (!sl_search_map(data, EXIT_CLSD, &exit_x, &exit_y))
		{
			data->map[exit_y][exit_x] = EXIT_OPEN;
			sl_print_midtext(data, "The exit opened!", -1, COL_WHITE);
			data->msgtimer = 150;
			sl_print_tile(data, exit_x, exit_y, 0);
		}
	}
	data->map[y][x] = CLBL_OLD;
	if (y > 0 && data->map[y - 1][x] == WALL)
		sl_print_tile(data, x, y - 1, 0);
	sl_grow_plr(data);
	return (0);
}

// returns 1 when the game ends
int	sl_upd_plmv(t_sl_data *data, int x, int y)
{
	(data->mvs)++;
	sl_print_mvs(data);
	if (data->map[y][x] == EXIT_OPEN)
	{
		sl_victory_screen(data);
		return (1);
	}
	return (0);
}

// only does the plr for now
int	sl_upd_crdir(t_sl_data *data, char cr, char dir)
{
	if (cr)
		return (1);
	data->plr[2] = ((dir == DIR_UP) * (FACE_BACK))
		+ ((dir == DIR_DOWN) * (FACE_FRONT))
		+ ((dir == DIR_LEFT) * (FACE_LEFT))
		+ ((dir == DIR_RIGHT) * (FACE_RIGHT));
	return (0);
}
