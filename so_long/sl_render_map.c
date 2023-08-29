/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:17:19 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/29 17:39:24 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sl_parse_tex(t_sl_data *data, char c, int w, int h)
{
	void	*mlx;

	mlx = data->mlx;
	if (c == '1')
	{
		mlx_put_image_to_window(mlx, data->win, data->tex->wall, w, h);
		return (0);
	}
	mlx_put_image_to_window(mlx, data->win, data->tex->empty, w, h);
	if (c == 'C')
		mlx_put_image_to_window(mlx, data->win, data->tex->clbl_new, w, h);
	else if (c == 'E')
		mlx_put_image_to_window(mlx, data->win, data->tex->exit_clsd, w, h);
	else if (c == 'P')
		mlx_put_image_to_window(mlx, data->win, data->tex->plr_front, w, h);
	return (0);
}

int	sl_render_map(t_sl_data *data)
{
	int	x;
	int	y;
	int	w;
	int	h;

	h = SL_HEAD;
	y = 0;
	while (data->map[y])
	{
		w = 0;
		x = 0;
		while (data->map[y][x])
		{
			sl_parse_tex(data, data->map[y][x], w, h);
			x++;
			w += SL_TILE_WIDTH;
		}
		y++;
		h += SL_TILE_HEIGHT;
	}
	return (0);
}
