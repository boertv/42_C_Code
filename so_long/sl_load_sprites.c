/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:28:57 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/13 19:29:14 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_init_sprs(t_sl_data *data)
{
	data->tex->floor1 = NULL;
	data->tex->wall = NULL;
	data->tex->wall_ban_r = NULL;
	data->tex->wall_ban_g = NULL;
	data->tex->wall_ban_b = NULL;
	data->tex->wall_ban_y = NULL;
	data->tex->clbl_new = NULL;
	data->tex->clbl_old = NULL;
	data->tex->exit_clsd = NULL;
	data->tex->exit_open = NULL;
	data->tex->plr_front = NULL;
	data->tex->plr_back = NULL;
	data->tex->plr_left = NULL;
	data->tex->plr_right = NULL;
	data->tex->width = TILE_WIDTH;
	data->tex->height = TILE_HEIGHT;
}

// destroys img if not NULL
void	sl_clear_sprs(t_sl_data *data)
{
	if (data->tex->floor1)
		mlx_destroy_image(data->mlx, data->tex->floor1);
	if (data->tex->wall)
		mlx_destroy_image(data->mlx, data->tex->wall);
	if (data->tex->wall_ban_r)
		mlx_destroy_image(data->mlx, data->tex->wall_ban_r);
	if (data->tex->wall_ban_g)
		mlx_destroy_image(data->mlx, data->tex->wall_ban_g);
	if (data->tex->wall_ban_b)
		mlx_destroy_image(data->mlx, data->tex->wall_ban_b);
	if (data->tex->wall_ban_y)
		mlx_destroy_image(data->mlx, data->tex->wall_ban_y);
	if (data->tex->clbl_new)
		mlx_destroy_image(data->mlx, data->tex->clbl_new);
	if (data->tex->clbl_old)
		mlx_destroy_image(data->mlx, data->tex->clbl_old);
	if (data->tex->exit_clsd)
		mlx_destroy_image(data->mlx, data->tex->exit_clsd);
	if (data->tex->exit_open)
		mlx_destroy_image(data->mlx, data->tex->exit_open);
	if (data->tex->plr_front)
		mlx_destroy_image(data->mlx, data->tex->plr_front);
	if (data->tex->plr_back)
		mlx_destroy_image(data->mlx, data->tex->plr_back);
	if (data->tex->plr_left)
		mlx_destroy_image(data->mlx, data->tex->plr_left);
	if (data->tex->plr_right)
		mlx_destroy_image(data->mlx, data->tex->plr_right);
}

void	*sl_load_sprite(t_sl_data *data, char *file, char **err)
{
	void	*ret;

	if (*err)
		return (NULL);
	ret = mlx_xpm_file_to_image(data->mlx, file,
			&(data->tex->width), &(data->tex->height));
	if (!ret)
	{
		*err = file;
		sl_clear_sprs(data);
	}
	return (ret);
}

// returns 1 if malloc or mlx failed, clears first
int	sl_load_texs(t_sl_data *data)
{
	char	*err;

	err = NULL;
	data->tex = malloc(sizeof(t_tex));
	if (!data->tex)
		return (sl_print_errno("t_tex malloc: ", 1));
	sl_init_sprs(data);
	data->tex->floor1 = sl_load_sprite(data, TEX_FLOOR1, &err);
	data->tex->wall = sl_load_sprite(data, TEX_WALL, &err);
	data->tex->wall_ban_r = sl_load_sprite(data, TEX_BAN_R, &err);
	data->tex->wall_ban_g = sl_load_sprite(data, TEX_BAN_G, &err);
	data->tex->wall_ban_b = sl_load_sprite(data, TEX_BAN_B, &err);
	data->tex->wall_ban_y = sl_load_sprite(data, TEX_BAN_Y, &err);
	data->tex->clbl_new = sl_load_sprite(data, TEX_CLBL_NEW, &err);
	data->tex->clbl_old = sl_load_sprite(data, TEX_CLBL_OLD, &err);
	data->tex->exit_clsd = sl_load_sprite(data, TEX_EXIT_CLSD, &err);
	data->tex->exit_open = sl_load_sprite(data, TEX_EXIT_OPEN, &err);
	data->tex->plr_front = sl_load_sprite(data, TEX_PLR_FRONT_16, &err);
	data->tex->plr_back = sl_load_sprite(data, TEX_PLR_BACK_16, &err);
	data->tex->plr_left = sl_load_sprite(data, TEX_PLR_LEFT_16, &err);
	data->tex->plr_right = sl_load_sprite(data, TEX_PLR_RIGHT_16, &err);
	data->plr_size = 16;
	if (err)
		ft_printf("%fdtexture error: make sure '%s' exists\n", 2, err);
	return (1 - (!err));
}
