/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:29:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/06 15:26:20 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns 1 if blocked by wall, 2 if by cr
static int	sl_move_check(t_sl_data *data, int *px, int *py, char dir)
{
	int	x;
	int	y;

	if (px)
		x = *px;
	if (py)
		y = *py;
	if (!px || !py)
	{
		x = data->plr[0];
		y = data->plr[1];
	}
	y -= (dir == DIR_UP);
	x -= (dir == DIR_LEFT);
	y += (dir == DIR_DOWN);
	x += (dir == DIR_RIGHT);
	if (x < 0 || y < 0 || x >= data->map_w || y >= data->map_h)
		return (1);
	if ((!px || !py) && SL_CHEATS)
		return (0);
	if (data->map[y][x] == WALL)
		return (1);
	if ((px && py) && ft_strchr(CR_CHARS_ALL, data->mask_cr[y][x]))
		return (2);
	return (0);
}

static int	sl_move_blocked(t_sl_data *data, int *px, int *py, int check)
{
	int	x;
	int	y;

	if (px)
		x = *px;
	if (py)
		y = *py;
	if (!px || !py)
	{
		x = data->plr[0];
		y = data->plr[1];
	}
	sl_print_tile(data, x, y, 0);
	if (px && py)
		return (check);
	sl_print_midtext(data, "You ran into a wall...", -1, MSG_COL);
	data->msgtimer = 50;
	return (check);
}

// returns 1 when game ends
static int	sl_move_upd(t_sl_data *data, int x, int y, char cr)
{
	if (!data->plr_size)
		return (1);
	if (!cr)
		if (sl_upd_plmv(data, x, y))
			return (1);
	if (!cr && data->map[y][x] == CLBL_NEW)
		sl_upd_clbl(data, x, y);
	return (0);
}

static void	sl_move_cr_2(t_sl_data *data, int **x, int **y, char dir)
{
	char	cr;
	int		oldx;
	int		oldy;

	cr = 1;
	if (!*x || !*y)
	{
		*x = &data->plr[0];
		*y = &data->plr[1];
		cr = 0;
	}
	oldx = **x;
	oldy = **y;
	**y -= (dir == DIR_UP);
	**x -= (dir == DIR_LEFT);
	**y += (dir == DIR_DOWN);
	**x += (dir == DIR_RIGHT);
	if (cr)
		data->mask_cr[**y][**x] = data->mask_cr[oldy][oldx] + ('a' - 'A');
	sl_print_tile(data, oldx, oldy, 0);
}

// updates x-y
// if x or y is NULL, plr is moved
// cr isn't moved but a lowercase letter is put where it is moving to
// returns 0 if moved, 1 if blocked by wall, 2 if by cr, 3 if turned
int	sl_move_cr(t_sl_data *data, int *x, int *y, char dir)
{
	char	cr;
	int		*ogx;
	int		*ogy;
	int		check;

	if (sl_upd_crdir(data, x, y, &dir))
		return (3);
	check = sl_move_check(data, x, y, dir);
	if (check)
		return (sl_move_blocked(data, x, y, check));
	ogx = x;
	ogy = y;
	cr = 1;
	if (!x || !y)
	{
		x = &data->plr[0];
		y = &data->plr[1];
		cr = 0;
	}
	sl_move_cr_2(data, &ogx, &ogy, dir);
	if (!cr)
		sl_hitreg(data);
	if (!sl_move_upd(data, *ogx, *ogy, cr) && data->immunetmr != SL_IMMUNITY)
		sl_print_tile(data, *ogx, *ogy, 0);
	return (0);
}
