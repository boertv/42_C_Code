/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_updates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:54:08 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/31 19:13:31 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_upd_clbl(t_sl_data *data, int x, int y)
{
	int	exit_x;
	int	exit_y;

	data->clbls--;
	//print updated clbl counter
	if (!data->clbls)
	{
		sl_search_map(data, EXIT_CLSD, &exit_x, &exit_y);
		data->map[exit_y][exit_x] = EXIT_OPEN;
		sl_print_tile(data, exit_x, exit_y, 0);
	}
	data->map[y][x] = CLBL_OLD;
	return (0);
}

int	sl_upd_plmv(t_sl_data *data, int x, int y)
{
	(data->mvs)++;
	sl_print_mvs(data);
	if (data->map[y][x] == EXIT_OPEN)
		sl_flush_loop(data);
	return (0);
}

int	sl_upd_pldir(t_sl_data *data, int x, int y, char dir)
{
	if (data->mask_cr[y][x] != PLAYER)
		return (1);
	data->plr[2] = ((dir == DIR_UP) * (FACE_BACK))
		+ ((dir == DIR_DOWN) * (FACE_FRONT))
		+ ((dir == DIR_LEFT) * (FACE_LEFT))
		+ ((dir == DIR_RIGHT) * (FACE_RIGHT));
	return (0);
}
