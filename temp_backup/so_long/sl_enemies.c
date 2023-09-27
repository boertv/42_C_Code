/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:25:32 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/25 17:51:23 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_bounce(t_sl_data *data, int x, int y, char dir)
{
	if (dir == DIR_RIGHT)
		data->mask_cr[y][x + 1] = KNIGHT_R;
	if (dir == DIR_LEFT)
		data->mask_cr[y][x - 1] = KNIGHT_L;
}

// returns 0 if not moved, 1 if moved in dir, 2 if in opposite dir
static int	sl_moving_knight(t_sl_data *data, int x, int y, char dir)
{
	int	check;

	check = sl_move_cr(data, &x, &y, dir);
	if (check == 2)
		sl_bounce(data, x, y, dir);
	if (check)
	{
		data->mask_cr[y][x] = (data->mask_cr[y][x] == KNIGHT_R) * KNIGHT_L
		+ (data->mask_cr[y][x] == KNIGHT_L) * KNIGHT_R;
		dir = (dir == DIR_LEFT) * DIR_RIGHT + (dir == DIR_RIGHT) * DIR_LEFT;
		check = sl_move_cr(data, &x, &y, dir);
		if (check == 2)
			sl_bounce(data, x, y, dir);
		if (check)
			return (0);
		return (2);
	}
	return (1);
}

static void	sl_move_knights_loop(t_sl_data *data, int x, int y)
{
	static int	moved_right = 0;

	if (!moved_right && data->mask_cr[y][x] == KNIGHT_R)
	{
		if (sl_moving_knight(data, x, y, DIR_RIGHT) == 1)
			moved_right = 2;
	}
	else if (data->mask_cr[y][x] == KNIGHT_L)
	{
		if (sl_moving_knight(data, x, y, DIR_LEFT) == 2)
			moved_right = 2;
	}
	if (moved_right)
		moved_right--;
}

void	sl_move_knights(t_sl_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->mask_cr[y])
	{
		x = 0;
		while (data->mask_cr[y][x])
		{
			sl_move_knights_loop(data, x, y);
			x++;
		}
		y++;
	}
}
