/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:29:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/19 17:22:09 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns 1 if blocked by wall, if something else updates dir?
static int	sl_move_check(t_sl_data *data, int x, int y, char dir)
{
	if (SL_CHEATS)
		return (0);
	y -= (dir == DIR_UP);
	x -= (dir == DIR_LEFT);
	y += (dir == DIR_DOWN);
	x += (dir == DIR_RIGHT);
	if (data->map[y][x] == WALL)
		return (1);
	return (0);
}

static int	sl_move_blocked(t_sl_data *data, int x, int y)
{
	if (data->plr[0] == x && data->plr[1] == y)
		sl_print_tile(data, x, y, 0);
	sl_print_midtext(data, "You ran into a wall...", -1, COL_WHITE);
	return (1);
}

static int	sl_move_upd(t_sl_data *data, int x, int y)
{
	if (data->plr[0] == x && data->plr[1] == y)
		sl_upd_plmv(data, x, y);
	if ((data->plr[0] == x && data->plr[1] == y) && data->map[y][x] == CLBL_NEW)
		sl_upd_clbl(data, x, y);
	return (0);
}

// updates x-y
// if x or y is NULL, plr is moved
int	sl_move_cr(t_sl_data *data, int *x, int *y, char dir)
{
	char	cr;
	int		oldx;
	int		oldy;

	cr = 1;
	if (!x || !y)
	{
		x = &data->plr[0];
		y = &data->plr[1];
		cr = 0;
	}
	oldx = *x;
	oldy = *y;
	sl_upd_pldir(data, *x, *y, dir);
	if (sl_move_check(data, *x, *y, dir))
		return (sl_move_blocked(data, *x, *y));
	*y -= (dir == DIR_UP);
	*x -= (dir == DIR_LEFT);
	*y += (dir == DIR_DOWN);
	*x += (dir == DIR_RIGHT);
	if (cr)
	{
		cr = data->mask_cr[oldy][oldx];
		data->mask_cr[oldy][oldx] = '0';
		data->mask_cr[*y][*x] = cr;
	}
	sl_print_tile(data, oldx, oldy, 0);
	sl_print_tile(data, *x, *y, 0);
	sl_move_upd(data, *x, *y);
	return (0);
}
