/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:28:57 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/28 17:59:17 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_init_sprs(t_sl_data *data)
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
	data->tex->width = SL_WIDTH;
	data->tex->heigth = SL_HEIGTH;
}

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

// returns 1 if malloc or mlx failed
int	sl_load_sprs(t_sl_data *data)
{
	data->tex = malloc(sizeof(t_tex));
	if (!data->tex)
		return (1);
	sl_init_sprs(data);
	data->tex->empty = mlx_xpm_file_to_image(data->mlx, "./textures/empty.xpm", &data->tex->width, &data->tex->heigth);
	data->tex->wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &data->tex->width, &data->tex->heigth);
	data->tex->clbl_new = mlx_xpm_file_to_image(data->mlx, "./textures/clbl_new.xpm", &data->tex->width, &data->tex->heigth);
	data->tex->clbl_old = mlx_xpm_file_to_image(data->mlx, "./textures/clbl_old.xpm", &data->tex->width, &data->tex->heigth);
	if (!data->tex->clbl_old)
		data->tex->clbl_old = data->tex->clbl_new;
	if (!data->tex->empty)
		return (1);
	return (0);
}
