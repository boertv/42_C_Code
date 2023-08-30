/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_window_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:08:30 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/30 18:06:50 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	sl_print_mask_cr(t_sl_data *data, int x, int y)
// {
// 	void	*mlx;
// 	int		w;
// 	int		h;

// 	mlx = data->mlx;
// 	w = x * TILE_WIDTH;
// 	h = (y * TILE_HEIGHT) + HEAD;
// 	if (data->mask_cr[y][x] == PLAYER)
// 		mlx_put_image_to_window(mlx, data->win, data->tex->pl, w, h);
// }

// SHOULDN'T ALL THESE [x][y] BE [y][x] INSTEAD ??? (update, i changed it..)
// doesn't print the player
// UPDATE SO IT PRINTS MASK VALUES??
int	sl_print_tile(t_sl_data *data, int x, int y)
{
	void	*mlx;
	int		w;
	int		h;

	mlx = data->mlx;
	w = x * TILE_WIDTH;
	h = (y * TILE_HEIGHT) + HEAD;
	if (data->map[y][x] == WALL)
	{
		mlx_put_image_to_window(mlx, data->win, data->tex->wall, w, h);
		return (0);
	}
	mlx_put_image_to_window(mlx, data->win, data->tex->empty, w, h);
	if (data->map[y][x] == CLBL_NEW)
		mlx_put_image_to_window(mlx, data->win, data->tex->clbl_new, w, h);
	else if (data->map[y][x] == CLBL_OLD)
		mlx_put_image_to_window(mlx, data->win, data->tex->clbl_old, w, h);
	else if (data->map[y][x] == EXIT_CLSD)
		mlx_put_image_to_window(mlx, data->win, data->tex->exit_clsd, w, h);
	else if (data->map[y][x] == EXIT_OPEN)
		mlx_put_image_to_window(mlx, data->win, data->tex->exit_open, w, h);
	return (0);
}

int	sl_print_plr(t_sl_data *data)
{
	void	*img;
	int		w;
	int		h;

	if (data->plr[2] == FACE_FRONT)
		img = data->tex->plr_front;
	else if (data->plr[2] == FACE_BACK)
		img = data->tex->plr_back;
	else if (data->plr[2] == FACE_LEFT)
		img = data->tex->plr_left;
	else if (data->plr[2] == FACE_RIGHT)
		img = data->tex->plr_right;
	else
		return (1);
	w = data->plr[0] * TILE_WIDTH;
	h = (data->plr[1] * TILE_HEIGHT) + HEAD;
	mlx_put_image_to_window(data->mlx, data->win, img, w, h);
	return (0);
}
