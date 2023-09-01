/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:29:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/01 18:46:24 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns 1 if blocked by wall, if something else updates dir?
static int	sl_move_check(t_sl_data *data, int x, int y, char dir)
{
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
	if (data->mask_cr[y][x] == PLAYER)
		sl_print_tile(data, x, y, 0);
	sl_print_midtext(data, "You ran into a wall...", -1, sl_create_color(255, 255, 255));
	return (1);
}

static int	sl_move_upd(t_sl_data *data, int x, int y)
{
	if (data->mask_cr[y][x] == PLAYER)
		sl_upd_plmv(data, x, y);
	if (data->mask_cr[y][x] == PLAYER && data->map[y][x] == CLBL_NEW)
		sl_upd_clbl(data, x, y);
	return (0);
}

// updates x-y
int	sl_move_cr(t_sl_data *data, int *x, int *y, char dir)
{
	char	cr;

	if (data->mask_cr[*y][*x] == PLAYER)
		sl_print_midtext(data, NULL, -1, 0);
	sl_upd_pldir(data, *x, *y, dir);
	if (sl_move_check(data, *x, *y, dir))
		return (sl_move_blocked(data, *x, *y));
	cr = data->mask_cr[*y][*x];
	data->mask_cr[*y][*x] = '0';
	sl_print_tile(data, *x, *y, 0);
	*y -= (dir == DIR_UP);
	*x -= (dir == DIR_LEFT);
	*y += (dir == DIR_DOWN);
	*x += (dir == DIR_RIGHT);
	data->mask_cr[*y][*x] = cr;
	sl_move_upd(data, *x, *y);
	sl_print_tile(data, *x, *y, 0);
	return (0);
}
