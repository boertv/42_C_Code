/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:12:47 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/09 16:12:14 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_plr_destroy(t_sl_data *data)
{
	if (data->tex->plr_front)
		mlx_destroy_image(data->mlx, data->tex->plr_front);
	if (data->tex->plr_back)
		mlx_destroy_image(data->mlx, data->tex->plr_back);
	if (data->tex->plr_left)
		mlx_destroy_image(data->mlx, data->tex->plr_left);
	if (data->tex->plr_right)
		mlx_destroy_image(data->mlx, data->tex->plr_right);
	data->tex->plr_front = NULL;
	data->tex->plr_back = NULL;
	data->tex->plr_left = NULL;
	data->tex->plr_right = NULL;
}

static void	sl_still_loading(t_sl_data *data, char **err)
{
	if (data->plr_size == 48)
	{
		data->tex->plr_front = sl_load_tex(data, TEX_PLR_FRONT_48, err);
		data->tex->plr_back = sl_load_tex(data, TEX_PLR_BACK_48, err);
		data->tex->plr_left = sl_load_tex(data, TEX_PLR_LEFT_48, err);
		data->tex->plr_right = sl_load_tex(data, TEX_PLR_RIGHT_48, err);
	}
	else if (data->plr_size == 64)
	{
		data->tex->plr_front = sl_load_tex(data, TEX_PLR_FRONT_64, err);
		data->tex->plr_back = sl_load_tex(data, TEX_PLR_BACK_64, err);
		data->tex->plr_left = sl_load_tex(data, TEX_PLR_LEFT_64, err);
		data->tex->plr_right = sl_load_tex(data, TEX_PLR_RIGHT_64, err);
	}
}

static void	sl_loading_plr_size(t_sl_data *data, char **err)
{
	if (data->plr_size == 16)
	{
		data->tex->plr_front = sl_load_tex(data, TEX_PLR_FRONT_16, err);
		data->tex->plr_back = sl_load_tex(data, TEX_PLR_BACK_16, err);
		data->tex->plr_left = sl_load_tex(data, TEX_PLR_LEFT_16, err);
		data->tex->plr_right = sl_load_tex(data, TEX_PLR_RIGHT_16, err);
	}
	else if (data->plr_size == 32)
	{
		data->tex->plr_front = sl_load_tex(data, TEX_PLR_FRONT_32, err);
		data->tex->plr_back = sl_load_tex(data, TEX_PLR_BACK_32, err);
		data->tex->plr_left = sl_load_tex(data, TEX_PLR_LEFT_32, err);
		data->tex->plr_right = sl_load_tex(data, TEX_PLR_RIGHT_32, err);
	}
	else
		sl_still_loading(data, err);
}

// returns 1 if already at max size
// destroy, change size, load, print tile
// if error: calls sl_flush_loop
int	sl_grow_plr(t_sl_data *data)
{
	char	*err;

	err = NULL;
	if (data->plr_size == 64)
		return (1);
	sl_plr_destroy(data);
	data->plr_size += 16;
	sl_loading_plr_size(data, &err);
	if (err)
	{
		ft_printf("%fdtexture error: make sure '%s' exists\n", 2, err);
		sl_flush_loop(data, 1);
	}
	if (data->munetmr != SL_IMMUNITY)
		sl_print_tile(data, data->plr[0], data->plr[1], 0);
	return (0);
}

// returns 1 if already at min size
// if 'min' == 1 plr changes to min size, and no printing
// destroy, change size, load, print tile
// if error: calls sl_flush_loop
int	sl_shrink_plr(t_sl_data *data, int min)
{
	char	*err;

	err = NULL;
	if (data->plr_size == 16)
	{
		data->plr_size = 0;
		return (1);
	}
	sl_plr_destroy(data);
	if (min)
		data->plr_size = 32;
	data->plr_size -= 16;
	sl_loading_plr_size(data, &err);
	if (err)
	{
		ft_printf("%fdtexture error: make sure '%s' exists\n", 2, err);
		sl_flush_loop(data, 1);
	}
	if (!min)
		sl_print_tile(data, data->plr[0], data->plr[1], 0);
	return (0);
}
