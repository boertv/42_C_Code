/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_tile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:41:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/13 19:09:54 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	sl_print_wall(t_sl_data *data, int x, int y, int offset)
{
	void	*mlx;
	int		w;
	int		h;

	mlx = data->mlx;
	w = ((x * TILE_WIDTH) + INDENT)
		+ ((offset <= 1000 && -1000 <= offset) * offset);
	h = ((y * TILE_HEIGHT) + HEAD) + ((offset > 1000 || -1000 > offset)
			* (offset + (((offset >= 0) * -1000) + ((offset < 0) * 1000))));
	mlx_put_image_to_window(mlx, data->win, data->tex->wall, w, h);
	mlx_put_image_to_window(mlx, data->win, data->tex->wall, w + 32, h);
	if (data->map_h > (size_t) y + 1 && data->map[y + 1][x] == EMPTY)
	{
		mlx_put_image_to_window(mlx, data->win, data->tex->wall_ban_r, w, h);
		mlx_put_image_to_window(mlx, data->win, data->tex->wall_ban_b, w + 32, h);
	}
	mlx_put_image_to_window(mlx, data->win, data->tex->wall, w, h + 32);
	mlx_put_image_to_window(mlx, data->win, data->tex->wall, w + 32, h + 32);
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
	if (data->map[y][x] == EMPTY || data->map[y][x] == CLBL_NEW
		|| data->map[y][x] == CLBL_OLD)
		sl_print_floor(data, x, y, offset);
	if (data->map[y][x] == WALL)
		sl_print_wall(data, x, y, offset);
	else if (data->map[y][x] == CLBL_NEW)
		mlx_put_image_to_window(mlx, data->win, data->tex->clbl_new, w, h);
	else if (data->map[y][x] == CLBL_OLD)
		mlx_put_image_to_window(mlx, data->win, data->tex->clbl_old, w, h);
	else if (data->map[y][x] == EXIT_CLSD)
		mlx_put_image_to_window(mlx, data->win, data->tex->exit_clsd, w, h);
	else if (data->map[y][x] == EXIT_OPEN)
		mlx_put_image_to_window(mlx, data->win, data->tex->exit_open, w, h);
	sl_print_mask_cr(data, x, y);
	return (0);
}
