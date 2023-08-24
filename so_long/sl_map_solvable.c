/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_solvable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:16:23 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/24 19:40:19 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_sl_tile	sl_solv_start(t_sl_data *data)
{
	t_sl_tile	tile;

	tile.x = 1;
	tile.y = 1;
	while(data->map[tile.x][tile.y] == '1')
	{
		tile.x++;
		if (!data->map[0][tile.x])
		{
			tile.x = 1;
			tile.y++;
		}
	}
}

int	sl_map_solvable(t_sl_data *data, t_sl_map *checks)
{
	int	col;
	int	exi;

	col = data->clbls;
	exi = 1;
}
