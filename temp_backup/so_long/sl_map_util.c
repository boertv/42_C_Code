/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:07:29 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/21 15:38:23 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// eight directions as digits like indicated on the numpad (e.g. up == 8)
// returns 0 if map edge is exceeded or bad dir, else the map char in dir
char	sl_getnb(t_sl_data *data, int x, int y, int dir)
{
	if (dir < 1 || dir > 9)
		return (0);
	if (dir >= 7 && y <= 0)
		return (0);
	if (dir % 3 == 0 && x + 1 >= data->map_w)
		return (0);
	if (dir <= 3 && y + 1 >= data->map_h)
		return (0);
	if ((dir - 1) % 3 == 0 && x <= 0)
		return (0);
	if (dir >= 7)
		y--;
	if (dir % 3 == 0)
		x++;
	if (dir <= 3)
		y++;
	if ((dir - 1) % 3 == 0)
		x--;
	return (data->map[y][x]);
}

// takes the four cardinal directions on the numpad: 8, 6, 2 and 4
// returns 1 if only walls are in that direction
int	sl_check_dir_wall(t_sl_data *data, int x, int y, int dir)
{
	int	*cord;
	int	limit;
	int	increment;

	if (dir != 8 && dir != 6 && dir != 2 && dir != 4)
		return (0);
	cord = &y;
	limit = data->map_h;
	if (dir == 4 || dir == 6)
	{
		cord = &x;
		limit = data->map_w;
	}
	increment = 1;
	if (dir == 8 || dir == 4)
		increment = -1;
	while (sl_getnb(data, x, y, dir) == WALL)
		*cord += increment;
	if ((increment < 0 && *cord == 0) || (increment > 0 && *cord + 1 >= limit))
		return (1);
	return (0);
}
