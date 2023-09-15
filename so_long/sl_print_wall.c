/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:16:35 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/15 19:49:37 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_put_wall_sides(t_sl_data *data, int x, int y, int offset)
{
	int		w;
	int		h;

	w = ((x * TILE_WIDTH) + INDENT)
		+ ((offset <= 1000 && -1000 <= offset) * offset);
	h = ((y * TILE_HEIGHT) + HEAD) + ((offset > 1000 || -1000 > offset)
			* (offset + (((offset >= 0) * -1000) + ((offset < 0) * 1000))));
	if (x > 0 && data->map[y][x - 1] != WALL)
		sl_put_imgs_tile(data, w, h, data->tex->edge_left);
	if (data->map_w > x + 1 && data->map[y][x + 1] != WALL)
		sl_put_imgs_tile(data, w + TLS, h, data->tex->edge_right);
	if (!(y > 0 && data->map[y - 1][x] != WALL)
		&& !(data->map_h < y + 1 && data->map[y + 1][x] != WALL))
	{
		if (x > 0 && data->map[y][x - 1] != WALL)
			sl_put_imgs_tile(data, w, h + TLS, data->tex->edge_left);
		if (data->map_w > x + 1 && data->map[y][x + 1] != WALL)
			sl_put_imgs_tile(data, w + TLS, h + TLS, data->tex->edge_right);
	}
}

static void	sl_put_wall_hub(t_sl_data *data, int x, int y, int offset)
{
	int		w;
	int		h;

	w = ((x * TILE_WIDTH) + INDENT)
		+ ((offset <= 1000 && -1000 <= offset) * offset);
	h = ((y * TILE_HEIGHT) + HEAD) + ((offset > 1000 || -1000 > offset)
			* (offset + (((offset >= 0) * -1000) + ((offset < 0) * 1000))));
	if (y > 0 && data->map[y - 1][x] != WALL)
	{
		sl_put_imgs_tile(data, -w, h + TLS, data->tex->wall);
		sl_put_imgs_tile(data, -w, h, data->tex->floor1);
		sl_put_imgs_tile(data, -w, h, data->tex->edge_top);
	}
	else if (data->map_h < y + 1 && data->map[y + 1][x] != WALL)
	{
		sl_put_imgs_tile(data, -w, h + TLS, data->tex->wall);
		sl_put_imgs_tile(data, -w, h, data->tex->edge_top);
	}
	sl_put_wall_sides(data, x, y, offset);
}

static void	sl_put_banner(t_sl_data *data, int x, int y, int offset)
{
	void	*m;
	int		w;
	int		h;

	m = data->mlx;
	w = ((x * TILE_WIDTH) + INDENT)
		+ ((offset <= 1000 && -1000 <= offset) * offset);
	h = ((y * TILE_HEIGHT) + HEAD) + ((offset > 1000 || -1000 > offset)
			* (offset + (((offset >= 0) * -1000) + ((offset < 0) * 1000))));
	if (x % 2 == 0)
	{
		mlx_put_image_to_window(m, data->win, data->tex->ban_r, w, h);
		mlx_put_image_to_window(m, data->win, data->tex->ban_g, w + TLS, h);
	}
	else
	{
		mlx_put_image_to_window(m, data->win, data->tex->ban_b, w, h);
		mlx_put_image_to_window(m, data->win, data->tex->ban_y, w + TLS, h);
	}
}

static void	sl_put_wallclbl(t_sl_data *data, int x, int y, int offset)
{
	void	*img;
	int		w;
	int		h;

	img = NULL;
	w = ((x * TILE_WIDTH) + INDENT)
		+ ((offset <= 1000 && -1000 <= offset) * offset);
	h = ((y * TILE_HEIGHT) + HEAD) + ((offset > 1000 || -1000 > offset)
			* (offset + (((offset >= 0) * -1000) + ((offset < 0) * 1000))));
	if (data->map[y + 1][x] == CLBL_NEW)
		img = data->tex->wall_clbl;
	else if (data->map[y + 1][x] == CLBL_OLD)
		img = data->tex->wall_old;
	if (x % 3 == 1)
		mlx_put_image_to_window(data->mlx, data->win, img, w, h + TLS);
	else
		mlx_put_image_to_window(data->mlx, data->win, img, w + TLS, h + TLS);
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
	if (data->map_h > y + 1 && data->map[y + 1][x] == EMPTY)
		sl_put_banner(data, x, y, offset);
	else
	{
		mlx_put_image_to_window(mlx, data->win, data->tex->wall, w, h);
		mlx_put_image_to_window(mlx, data->win, data->tex->wall, w + TLS, h);
	}
	mlx_put_image_to_window(mlx, data->win, data->tex->wall, w, h + TLS);
	mlx_put_image_to_window(mlx, data->win, data->tex->wall, w + TLS, h + TLS);
	if (data->map_h > y + 1
		&& (data->map[y + 1][x] == CLBL_NEW || data->map[y + 1][x] == CLBL_OLD))
		sl_put_wallclbl(data, x, y, offset);
}
