/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:16:35 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/04 18:07:44 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_put_banner(t_sl_data *data, int x, int y, int offset)
{
	void	*m;
	int		w;
	int		h;

	m = data->mlx;
	w = sl_cv_cdpx(x, 'x', offset);
	h = sl_cv_cdpx(y, 'y', offset) + TLS;
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

	w = sl_cv_cdpx(x, 'x', offset);
	h = sl_cv_cdpx(y, 'y', offset);
	if (sl_getnb(data, x, y, 8) && sl_getnb(data, x, y, 8) != WALL)
		sl_put_imgs_tile(data, -w, h, data->tex->wall);
	if (sl_getnb(data, x, y, 9) && sl_getnb(data, x, y, 9) != WALL)
		sl_put_imgs_tile(data, w + TLS, h, data->tex->wall);
	if (sl_getnb(data, x, y, 6) && sl_getnb(data, x, y, 6) != WALL)
		sl_put_imgs_tile(data, w + TLS, -h, data->tex->wall);
	if (sl_getnb(data, x, y, 3) && sl_getnb(data, x, y, 3) != WALL)
		sl_put_imgs_tile(data, w + TLS, h + TLS, data->tex->wall);
	if (sl_getnb(data, x, y, 2) && sl_getnb(data, x, y, 2) != WALL)
		sl_put_imgs_tile(data, -w, h + TLS, data->tex->wall);
	if (sl_getnb(data, x, y, 1) && sl_getnb(data, x, y, 1) != WALL)
		sl_put_imgs_tile(data, w, h + TLS, data->tex->wall);
	if (sl_getnb(data, x, y, 4) && sl_getnb(data, x, y, 4) != WALL)
		sl_put_imgs_tile(data, w, -h, data->tex->wall);
	if (sl_getnb(data, x, y, 7) && sl_getnb(data, x, y, 7) != WALL)
		sl_put_imgs_tile(data, w, h, data->tex->wall);
}

static void	sl_put_wallclbl(t_sl_data *data, int x, int y, int offset)
{
	void	*img;
	int		w;
	int		h;

	img = NULL;
	w = sl_cv_cdpx(x, 'x', offset);
	h = sl_cv_cdpx(y, 'y', offset);
	if (data->map[y + 1][x] == CLBL_NEW)
		img = data->tex->wall_clbl;
	else if (data->map[y + 1][x] == CLBL_OLD)
		img = data->tex->wall_old;
	if (x % 3 == 1)
		mlx_put_image_to_window(data->mlx, data->win, img, w, h + TLS);
	else
		mlx_put_image_to_window(data->mlx, data->win, img, w + TLS, h + TLS);
}

// returns 1 if nothing else needs printing
static int	sl_bottom_wall(t_sl_data *data, int x, int y, int os)
{
	int		temp;

	if (y + 1 < data->map_h)
		return (0);
	temp = sl_getnb(data, x, y, 8);
	if (temp == WALL || temp == 0)
		return (1);
	sl_put_imgs_tile(data, -sl_cv_cdpx(x, 'x', os),
		sl_cv_cdpx(y, 'y', os), data->tex->floor_edge);
	return (1);
}

void	sl_print_wall(t_sl_data *data, int x, int y, int offset)
{
	data->cords[0] = sl_cv_cdpx(x, 'x', offset) + 2;
	data->cords[1] = sl_cv_cdpx(y, 'y', offset) + 2;
	sl_print_rectangle(data, TILE_WIDTH - 4, TILE_HEIGHT - 4, BG_COL);
	if (sl_bottom_wall(data, x, y, offset))
		return ;
	sl_put_wall_hub(data, x, y, offset);
	if (sl_getnb(data, x, y, 2) && sl_getnb(data, x, y, 2) != WALL)
		sl_put_banner(data, x, y, offset);
	if (sl_getnb(data, x, y, 2) == CLBL_NEW
		|| sl_getnb(data, x, y, 2) == CLBL_OLD)
		sl_put_wallclbl(data, x, y, offset);
}
