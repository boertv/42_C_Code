/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_updates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:54:08 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/13 19:28:19 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_upd_clbl(t_sl_data *data, int x, int y)
{
	int	exit_x;
	int	exit_y;

	data->clbls++;
	sl_print_clbl(data);
	if (data->clbls >= data->clblt)
	{
		if (!sl_search_map(data, EXIT_CLSD, &exit_x, &exit_y))
		{
			data->map[exit_y][exit_x] = EXIT_OPEN;
			sl_print_midtext(data, "The exit opened!", -1, COL_WHITE);
			sl_print_tile(data, exit_x, exit_y, 0);
		}
	}
	data->map[y][x] = CLBL_OLD;
	return (0);
}

int	sl_upd_plmv(t_sl_data *data, int x, int y)
{
	(data->mvs)++;
	sl_print_mvs(data);
	if (data->map[y][x] == EXIT_OPEN)
		sl_flush_loop(data);
	return (0);
}

int	sl_upd_pldir(t_sl_data *data, int x, int y, char dir)
{
	if (data->mask_cr[y][x] != PLAYER)
		return (1);
	data->plr[2] = ((dir == DIR_UP) * (FACE_BACK))
		+ ((dir == DIR_DOWN) * (FACE_FRONT))
		+ ((dir == DIR_LEFT) * (FACE_LEFT))
		+ ((dir == DIR_RIGHT) * (FACE_RIGHT));
	return (0);
}

// destroy, load, change size, print tile
// if error: calls sl_flush_loop
void	sl_grow_plr(t_sl_data *data)
{
	char	*err;

	err = NULL;
	if (data->plr_size == 64)
		return ;
	mlx_destroy_image(data->mlx, data->tex->plr_front);
	mlx_destroy_image(data->mlx, data->tex->plr_back);
	mlx_destroy_image(data->mlx, data->tex->plr_left);
	mlx_destroy_image(data->mlx, data->tex->plr_right);
	data->tex->plr_front = NULL;
	data->tex->plr_back = NULL;
	data->tex->plr_left = NULL;
	data->tex->plr_right = NULL;
	if (data->plr_size == 16)
	{
		data->tex->plr_front = sl_load_sprite(data, TEX_PLR_FRONT_32, &err);
		data->tex->plr_back = sl_load_sprite(data, TEX_PLR_BACK_32, &err);
		data->tex->plr_left = sl_load_sprite(data, TEX_PLR_LEFT_32, &err);
		data->tex->plr_right = sl_load_sprite(data, TEX_PLR_RIGHT_32, &err);
		data->plr_size = 32;
	}
	else if (data->plr_size == 32)
	{
		data->tex->plr_front = sl_load_sprite(data, TEX_PLR_FRONT_48, &err);
		data->tex->plr_back = sl_load_sprite(data, TEX_PLR_BACK_48, &err);
		data->tex->plr_left = sl_load_sprite(data, TEX_PLR_LEFT_48, &err);
		data->tex->plr_right = sl_load_sprite(data, TEX_PLR_RIGHT_48, &err);
		data->plr_size = 48;
	}
	else if (data->plr_size == 48)
	{
		data->tex->plr_front = sl_load_sprite(data, TEX_PLR_FRONT_64, &err);
		data->tex->plr_back = sl_load_sprite(data, TEX_PLR_BACK_64, &err);
		data->tex->plr_left = sl_load_sprite(data, TEX_PLR_LEFT_64, &err);
		data->tex->plr_right = sl_load_sprite(data, TEX_PLR_RIGHT_64, &err);
		data->plr_size = 64;
	}
	if (err)
	{
		ft_printf("%fdtexture error: make sure '%s' exists\n", 2, err);
		sl_flush_loop(data);
	}
	sl_print_tile(data, data->plr[0], data->plr[1], 0);
}
