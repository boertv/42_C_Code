/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:07:29 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/19 16:33:43 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// eight directions as digits like indicated on the numpad (e.g. up == 8)
// returns 0 if map edge is exceeded or bad dir, else the map char in dir
char	sl_neighbour(t_sl_data *data, int x, int y, int dir)
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
