/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:29:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/30 18:07:33 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns 1 and updates dir if cr runs into something; 1: wall, 2: N/A
static int	sl_move_check(t_sl_data *data, int x, int y, char *dir)
{
	y += (dir == DIR_UP);
	y -= (dir == DIR_DOWN);
	x += (dir == DIR_RIGHT);
	x -= (dir == DIR_LEFT);
	if (data->map[y][x] == WALL)
		*dir = 1;
	else
		return (0);
	return (1);
}

// ouchie BONK tile-flicker or sumn
static int	sl_move_blocked(t_sl_data *data, int x, int y, char obstcl)
{
	(void)data;
	(void)x;
	(void)y;
	(void)obstcl;
ft_printf("you ran into a wall...\n");
	return (1);
}

static int	sl_move_upd(t_sl_data *data, int x, int y, char cr)
{
	if (cr == PLAYER)
		//update mvs count and print
		(void)cr;
	if (cr == PLAYER && data->map[y][x] == CLBL_NEW)
	{
		data->clbls--;
		//print updated counter and check if 0 (open exit)
		data->map[y][x] = CLBL_OLD;
	}
	return (0);
}

// updates x-y
int	sl_move_cr(t_sl_data *data, int *x, int *y, char dir)
{
	char	cr;

	if (sl_move_check(data, *x, *y, &dir))
		return (sl_move_blocked(data, *x, *y, dir));
	cr = data->mask_cr[*y][*x];
	data->mask_cr[*y][*x] = '0';
	sl_print_tile(data, *x, *y);
	*y += (dir == DIR_UP);
	*y -= (dir == DIR_DOWN);
	*x += (dir == DIR_RIGHT);
	*x -= (dir == DIR_LEFT);
	data->plr[2] = ((dir == DIR_UP) * (FACE_BACK))
		+ ((dir == DIR_DOWN) * (FACE_FRONT)) + ((dir == DIR_LEFT) * (FACE_LEFT))
		+ ((dir == DIR_RIGHT) * (FACE_RIGHT));
	data->mask_cr[*y][*x] = cr;
	sl_move_upd(data, *x, *y, cr);
	sl_print_tile(data, *x, *y);
//if plr... else?
sl_print_plr(data);
	return (0);
}
