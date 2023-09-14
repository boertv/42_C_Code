/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_cr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:21:41 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/14 17:40:24 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_print_plr(t_sl_data *data, int w, int h)
{
	void	*img;

	img = NULL;
	w += (data->plr_size == 16) * 24;
	h += (data->plr_size == 16) * 16;
	w += (data->plr_size == 32) * 16;
	h += (data->plr_size == 32) * 8;
	w += (data->plr_size == 48) * 8;
	h -= (data->plr_size == 64) * 8;
	if (data->plr[2] == FACE_FRONT)
		img = data->tex->plr_front;
	else if (data->plr[2] == FACE_BACK)
		img = data->tex->plr_back;
	else if (data->plr[2] == FACE_LEFT)
		img = data->tex->plr_left;
	else if (data->plr[2] == FACE_RIGHT)
		img = data->tex->plr_right;
	mlx_put_image_to_window(data->mlx, data->win, img, w, h);
}

int	sl_print_mask_cr(t_sl_data *data, int x, int y)
{
	int		w;
	int		h;

	w = (x * TILE_WIDTH) + INDENT;
	h = (y * TILE_HEIGHT) + HEAD;
	if (data->mask_cr[y][x] == PLAYER)
		sl_print_plr(data, w, h);
	else
		return (1);
	return (0);
}
