/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:16:35 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/19 16:57:18 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_put_banner(t_sl_data *data, int x, int y, int offset)
{
	void	*m;
	int		w;
	int		h;

	m = data->mlx;
	w = ((x * TILE_WIDTH) + INDENT)
		+ ((offset <= 1000 && -1000 <= offset) * offset);
	h = TLS + ((y * TILE_HEIGHT) + HEAD) + ((offset > 1000 || -1000 > offset)
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

static void	sl_put_wall_hub(t_sl_data *data, int x, int y, int offset)
{
	int		w;
	int		h;

	w = ((x * TILE_WIDTH) + INDENT)
		+ ((offset <= 1000 && -1000 <= offset) * offset);
	h = ((y * TILE_HEIGHT) + HEAD) + ((offset > 1000 || -1000 > offset)
			* (offset + (((offset >= 0) * -1000) + ((offset < 0) * 1000))));
	if (sl_neighbour(data, x, y, 8) && sl_neighbour(data, x, y, 8) != WALL)
		sl_put_imgs_tile(data, -w, h, data->tex->wall);
	if (sl_neighbour(data, x, y, 9) && sl_neighbour(data, x, y, 9) != WALL)
		sl_put_imgs_tile(data, w + TLS, h, data->tex->wall);
	if (sl_neighbour(data, x, y, 6) && sl_neighbour(data, x, y, 6) != WALL)
		sl_put_imgs_tile(data, w + TLS, -h, data->tex->wall);
	if (sl_neighbour(data, x, y, 3) && sl_neighbour(data, x, y, 3) != WALL)
		sl_put_imgs_tile(data, w + TLS, h + TLS, data->tex->wall);
	if (sl_neighbour(data, x, y, 2) && sl_neighbour(data, x, y, 2) != WALL)
		sl_put_imgs_tile(data, -w, h + TLS, data->tex->wall);
	if (sl_neighbour(data, x, y, 1) && sl_neighbour(data, x, y, 1) != WALL)
		sl_put_imgs_tile(data, w, h + TLS, data->tex->wall);
	if (sl_neighbour(data, x, y, 4) && sl_neighbour(data, x, y, 4) != WALL)
		sl_put_imgs_tile(data, w, -h, data->tex->wall);
	if (sl_neighbour(data, x, y, 7) && sl_neighbour(data, x, y, 7) != WALL)
		sl_put_imgs_tile(data, w, h, data->tex->wall);
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
	sl_put_wall_hub(data, x, y, offset);
	if (sl_neighbour(data, x, y, 2) && sl_neighbour(data, x, y, 2) != WALL)
		sl_put_banner(data, x, y, offset);
	if (sl_neighbour(data, x, y, 2) == CLBL_NEW
		|| sl_neighbour(data, x, y, 2) == CLBL_OLD)
		sl_put_wallclbl(data, x, y, offset);
}
