/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:17:19 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/06 16:16:41 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns 1 if c can't be found, updates x-y
// starts at [1][1]
int	sl_search_map(t_sl_data *data, char c, int *x, int *y)
{
	*y = 1;
	while (data->map[*y])
	{
		*x = 1;
		while (data->map[*y][*x])
		{
			if (data->map[*y][*x] == c)
				return (0);
			(*x)++;
		}
		(*y)++;
	}
	return (1);
}

void	sl_render_map(t_sl_data *data)
{
	int	x;
	int	y;

	data->cords[0] = 0;
	data->cords[1] = 0;
	sl_print_rectangle(data, data->win_w, data->win_h, BG_COL);
	sl_print_game_frame(data, COL_WHITE);
	sl_print_reset(data);
	sl_print_mvs(data);
	sl_print_clbl(data);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			sl_print_tile(data, x, y, 0);
			x++;
		}
		y++;
	}
}

// returns 1 if malloc (mask) failed ((or 'P' isn't found somehow))
int	sl_init_map(t_sl_data *data)
{
	if (sl_create_mask_cr(data))
		return (1);
	if (sl_search_map(data, PLAYER, &data->plr[0], &data->plr[1]))
		return (1);
	data->map[data->plr[1]][data->plr[0]] = EMPTY;
	data->plr[2] = FACE_FRONT;
	data->plr_size = 16;
	data->mvs = 0;
	data->clbls = 0;
	sl_render_map(data);
	return (0);
}
