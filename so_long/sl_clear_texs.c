/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_clear_texs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:49:00 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/05 17:43:26 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_destroy_ifn_null(t_sl_data *data, void *img)
{
	if (img)
		mlx_destroy_image(data->mlx, img);
}

static void	sl_destroy_all_texs(t_sl_data *data)
{
	sl_destroy_ifn_null(data, data->tex->floor1);
	sl_destroy_ifn_null(data, data->tex->floor2);
	sl_destroy_ifn_null(data, data->tex->floor3);
	sl_destroy_ifn_null(data, data->tex->floor4);
	sl_destroy_ifn_null(data, data->tex->floor5);
	sl_destroy_ifn_null(data, data->tex->floor_edge);
	sl_destroy_ifn_null(data, data->tex->wall);
	sl_destroy_ifn_null(data, data->tex->wall_clbl);
	sl_destroy_ifn_null(data, data->tex->wall_old);
	sl_destroy_ifn_null(data, data->tex->ban_r);
	sl_destroy_ifn_null(data, data->tex->ban_g);
	sl_destroy_ifn_null(data, data->tex->ban_b);
	sl_destroy_ifn_null(data, data->tex->ban_y);
	sl_destroy_ifn_null(data, data->tex->clbl_new);
	sl_destroy_ifn_null(data, data->tex->clbl_old);
	sl_destroy_ifn_null(data, data->tex->clbl_base);
	sl_destroy_ifn_null(data, data->tex->exit_clsd);
	sl_destroy_ifn_null(data, data->tex->exit_open);
	sl_destroy_ifn_null(data, data->tex->plr_front);
	sl_destroy_ifn_null(data, data->tex->plr_back);
	sl_destroy_ifn_null(data, data->tex->plr_left);
	sl_destroy_ifn_null(data, data->tex->plr_right);
	sl_destroy_ifn_null(data, data->tex->knight_l);
	sl_destroy_ifn_null(data, data->tex->knight_r);
}

// destroys img if not NULL
void	sl_clear_texs(t_sl_data *data)
{
	if (!data->tex)
		return ;
	sl_destroy_all_texs(data);
	free(data->tex);
	data->tex = NULL;
}
