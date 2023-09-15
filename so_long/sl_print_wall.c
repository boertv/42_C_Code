/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:16:35 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/15 18:03:36 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// img is put at [w][h] and [w + TLS][h + TLS] depending on which is -
// if both are negative, it prints all four. if none are -, it prints just one
static void	sl_put_img(t_sl_data *data, int w, int h, void *img)
{
	int	ah;
	int	aw;

	ah = h;
	if (ah < 0)
		ah *= -1;
	aw = w;
	if (aw < 0)
		aw *= -1;
	if (w < 0 && h < 0)
		mlx_put_image_to_window(data->mlx, data->win, img, aw + TLS, ah + TLS);
	mlx_put_image_to_window(data->mlx, data->win, img, aw, ah);
	if (w < 0)
		mlx_put_image_to_window(data->mlx, data->win, img, aw + TLS, ah);
	if (h < 0)
		mlx_put_image_to_window(data->mlx, data->win, img, aw, ah + TLS);
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
		sl_put_img(data, -w, h + TLS, data->tex->wall);
		sl_put_img(data, -w, h, data->tex->floor1);
		sl_put_img(data, -w, h, data->tex->edge_top);
	}
	if (data->map_h < y + 1 && data->map[y + 1][x] != WALL)
	{
		sl_put_img(data, -w, h + TLS, data->tex->wall);
		sl_put_img(data, -w, h, data->tex->edge_top);
	}
// print sides too?
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
