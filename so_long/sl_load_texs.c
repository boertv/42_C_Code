/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_texs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:28:57 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/10 13:32:07 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_init_texs(t_sl_data *data)
{
	data->tex->floor1 = NULL;
	data->tex->floor2 = NULL;
	data->tex->floor3 = NULL;
	data->tex->floor4 = NULL;
	data->tex->floor5 = NULL;
	data->tex->floor_edge = NULL;
	data->tex->wall = NULL;
	data->tex->wall_clbl = NULL;
	data->tex->wall_old = NULL;
	data->tex->ban_r = NULL;
	data->tex->ban_g = NULL;
	data->tex->ban_b = NULL;
	data->tex->ban_y = NULL;
	data->tex->clbl_new = NULL;
	data->tex->clbl_old = NULL;
	data->tex->clbl_base = NULL;
	data->tex->exit_clsd = NULL;
	data->tex->exit_open = NULL;
	data->tex->plr_front = NULL;
	data->tex->plr_back = NULL;
	data->tex->plr_left = NULL;
	data->tex->plr_right = NULL;
	data->tex->knight_l = NULL;
	data->tex->knight_r = NULL;
}

void	*sl_load_tex(t_sl_data *data, char *file, char **err)
{
	void	*ret;

	if (*err)
		return (NULL);
	ret = mlx_xpm_file_to_image(data->mlx, file, &data->tex->w, &data->tex->h);
	if (!ret)
		*err = file;
	return (ret);
}

static void	sl_load_all(t_sl_data *data, char **err)
{
	data->tex->floor1 = sl_load_tex(data, TEX_FLOOR1, err);
	data->tex->floor2 = sl_load_tex(data, TEX_FLOOR2, err);
	data->tex->floor3 = sl_load_tex(data, TEX_FLOOR3, err);
	data->tex->floor4 = sl_load_tex(data, TEX_FLOOR4, err);
	data->tex->floor5 = sl_load_tex(data, TEX_FLOOR5, err);
	data->tex->floor_edge = sl_load_tex(data, TEX_FLOOR_EDGE, err);
	data->tex->wall = sl_load_tex(data, TEX_WALL, err);
	data->tex->wall_clbl = sl_load_tex(data, TEX_CLBLWALL_NEW, err);
	data->tex->wall_old = sl_load_tex(data, TEX_CLBLWALL_OLD, err);
	data->tex->ban_r = sl_load_tex(data, TEX_BAN_R, err);
	data->tex->ban_g = sl_load_tex(data, TEX_BAN_G, err);
	data->tex->ban_b = sl_load_tex(data, TEX_BAN_B, err);
	data->tex->ban_y = sl_load_tex(data, TEX_BAN_Y, err);
	data->tex->clbl_new = sl_load_tex(data, TEX_CLBL_NEW, err);
	data->tex->clbl_old = sl_load_tex(data, TEX_CLBL_OLD, err);
	data->tex->clbl_base = sl_load_tex(data, TEX_CLBLWALL_FLOOR, err);
	data->tex->exit_clsd = sl_load_tex(data, TEX_EXIT_CLSD, err);
	data->tex->exit_open = sl_load_tex(data, TEX_EXIT_OPEN, err);
	data->tex->plr_front = sl_load_tex(data, TEX_PLR_FRONT_16, err);
	data->tex->plr_back = sl_load_tex(data, TEX_PLR_BACK_16, err);
	data->tex->plr_left = sl_load_tex(data, TEX_PLR_LEFT_16, err);
	data->tex->plr_right = sl_load_tex(data, TEX_PLR_RIGHT_16, err);
	data->tex->knight_l = sl_load_tex(data, TEX_KNIGHT_L, err);
	data->tex->knight_r = sl_load_tex(data, TEX_KNIGHT_R, err);
}

// returns 1 if malloc or mlx failed, clears first
int	sl_load_texs(t_sl_data *data)
{
	char	*err;

	err = NULL;
	data->tex = malloc(sizeof(t_tex));
	if (!data->tex)
		return (sl_print_errno("general textures malloc: ", 1));
	sl_init_texs(data);
	data->tex->w = TILE_WIDTH;
	data->tex->h = TILE_HEIGHT;
	sl_load_all(data, &err);
	if (err)
	{
		ft_printf("%fdtexture error: make sure '%s' exists\n", 2, err);
		return (1);
	}
	if (sl_load_animations(data))
	{
		sl_clear_texs(data);
		return (1);
	}
	return (0);
}
