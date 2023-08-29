/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:28:57 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/29 16:20:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_init_sprs(t_sl_data *data)
{
	data->tex->empty = NULL;
	data->tex->wall = NULL;
	data->tex->clbl_new = NULL;
	data->tex->clbl_old = NULL;
	data->tex->exit_clsd = NULL;
	data->tex->exit_open = NULL;
	data->tex->plr_front = NULL;
	data->tex->plr_back = NULL;
	data->tex->plr_left = NULL;
	data->tex->plr_right = NULL;
	data->tex->width = SL_TILE_WIDTH;
	data->tex->height = SL_TILE_HEIGHT;
}

// destroys img if not NULL
void	sl_clear_sprs(t_sl_data *data)
{
	if (data->tex->empty)
		mlx_destroy_image(data->mlx, data->tex->empty);
	if (data->tex->wall)
		mlx_destroy_image(data->mlx, data->tex->wall);
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

static void	*sl_load_sprite(t_sl_data *data, char *file, char **err)
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
	data->tex->empty = sl_load_sprite(data, SL_TEX_EMPTY, &err);
	data->tex->wall = sl_load_sprite(data, SL_TEX_WALL, &err);
	data->tex->clbl_new = sl_load_sprite(data, SL_TEX_CLBL_NEW, &err);
	data->tex->clbl_old = sl_load_sprite(data, SL_TEX_CLBL_OLD, &err);
	data->tex->exit_clsd = sl_load_sprite(data, SL_TEX_EXIT_CLSD, &err);
	data->tex->exit_open = sl_load_sprite(data, SL_TEX_EXIT_OPEN, &err);
	data->tex->plr_front = sl_load_sprite(data, SL_TEX_PLR_FRONT, &err);
	data->tex->plr_back = sl_load_sprite(data, SL_TEX_PLR_BACK, &err);
	data->tex->plr_left = sl_load_sprite(data, SL_TEX_PLR_LEFT, &err);
	data->tex->plr_right = sl_load_sprite(data, SL_TEX_PLR_RIGHT, &err);
	if (err)
		ft_printf("%fdtexture error: make sure '%s' exists\n", 2, err);
	return (1 - (!err));
}