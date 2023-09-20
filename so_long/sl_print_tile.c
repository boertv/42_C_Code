/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_tile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:41:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/20 13:18:45 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_put_floorclbl(t_sl_data *data, int x, int y, int offset)
{
	void	*img;
	int		w;
	int		h;

	img = NULL;
	w = ((x % 3 != 1) * TLS) + ((x * TILE_WIDTH) + INDENT)
		+ ((offset <= 1000 && -1000 <= offset) * offset);
	h = ((y * TILE_HEIGHT) + HEAD) + ((offset > 1000 || -1000 > offset)
			* (offset + (((offset >= 0) * -1000) + ((offset < 0) * 1000))));
	img = data->tex->clbl_base;
	if (sl_neighbour(data, x, y, 8) != WALL)
	{
		if (data->map[y][x] == CLBL_NEW)
			img = data->tex->clbl_new;
		else if (data->map[y][x] == CLBL_OLD)
			img = data->tex->clbl_old;
		if (y % 3 != 1)
			h += TLS;
	}
	mlx_put_image_to_window(data->mlx, data->win, img, w, h);
}

void	sl_print_floor(t_sl_data *data, int x, int y, int offset)
{
	void	*mlx;
	int		w;
	int		h;

	mlx = data->mlx;
	w = ((x * TILE_WIDTH) + INDENT)
		+ ((offset <= 1000 && -1000 <= offset) * offset);
	h = ((y * TILE_HEIGHT) + HEAD) + ((offset > 1000 || -1000 > offset)
			* (offset + (((offset >= 0) * -1000) + ((offset < 0) * 1000))));
	mlx_put_image_to_window(mlx, data->win, data->tex->floor1, w, h);
	mlx_put_image_to_window(mlx, data->win, data->tex->floor1, w + 32, h);
	mlx_put_image_to_window(mlx, data->win, data->tex->floor1, w, h + 32);
	mlx_put_image_to_window(mlx, data->win, data->tex->floor1, w + 32, h + 32);
}

//prints map and mask_cr
// if -1000 < offset < 1000 it is added to width, else the diff is to height
int	sl_print_tile(t_sl_data *data, int x, int y, int offset)
{
	void	*mlx;
	int		w;
	int		h;

	mlx = data->mlx;
	w = ((x * TILE_WIDTH) + INDENT)
		+ ((offset <= 1000 && -1000 <= offset) * offset);
	h = ((y * TILE_HEIGHT) + HEAD) + ((offset > 1000 || -1000 > offset)
			* (offset + (((offset >= 0) * -1000) + ((offset < 0) * 1000))));
	if (data->map[y][x] != WALL)
		sl_print_floor(data, x, y, offset);
	if (data->map[y][x] == CLBL_NEW || data->map[y][x] == CLBL_OLD)
		sl_put_floorclbl(data, x, y, offset);
	if (data->map[y][x] == WALL)
		sl_print_wall(data, x, y, offset);
	if (data->map[y][x] == EXIT_CLSD)
		mlx_put_image_to_window(mlx, data->win, data->tex->exit_clsd, w, h);
	if (data->map[y][x] == EXIT_OPEN)
		mlx_put_image_to_window(mlx, data->win, data->tex->exit_open, w, h);
	sl_print_mask_cr(data, x, y);
	return (0);
}
