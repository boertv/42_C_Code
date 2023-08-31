/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:29:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/31 15:46:20 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns 1 and updates dir if cr runs into something; 1: wall, 2: N/A
static int	sl_move_check(t_sl_data *data, int x, int y, char *dir)
{
	y -= (*dir == DIR_UP);
	x -= (*dir == DIR_LEFT);
	y += (*dir == DIR_DOWN);
	x += (*dir == DIR_RIGHT);
	if (data->map[y][x] == WALL)
		*dir = 1;
	else
		return (0);
	return (1);
}

// ouchie BONK tile-flicker or sumn
static int	sl_move_blocked(t_sl_data *data, int x, int y, char obstcl)
{
	if (data->mask_cr[y][x] == PLAYER)
		sl_print_tile(data, x, y);
	(void)data;
	(void)x;
	(void)y;
	(void)obstcl;
ft_printf("you ran into a wall...\n");
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

	sl_upd_pldir(data, *x, *y, dir);
	if (sl_move_check(data, *x, *y, &dir))
		return (sl_move_blocked(data, *x, *y, dir));
	cr = data->mask_cr[*y][*x];
	data->mask_cr[*y][*x] = '0';
	sl_print_tile(data, *x, *y);
	*y -= (dir == DIR_UP);
	*x -= (dir == DIR_LEFT);
	*y += (dir == DIR_DOWN);
	*x += (dir == DIR_RIGHT);
	data->mask_cr[*y][*x] = cr;
	sl_move_upd(data, *x, *y);
	sl_print_tile(data, *x, *y);
	return (0);
}
