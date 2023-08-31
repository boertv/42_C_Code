/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:35:03 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/31 18:52:04 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_create_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	sl_print_mask_cr(t_sl_data *data, int x, int y)
{
	void	*img;
	int		w;
	int		h;

	w = (x * TILE_WIDTH) + INDENT;
	h = (y * TILE_HEIGHT) + HEAD;
	img = NULL;
	if (data->mask_cr[y][x] == PLAYER)
	{
		if (data->plr[2] == FACE_FRONT)
			img = data->tex->plr_front;
		else if (data->plr[2] == FACE_BACK)
			img = data->tex->plr_back;
		else if (data->plr[2] == FACE_LEFT)
			img = data->tex->plr_left;
		else if (data->plr[2] == FACE_RIGHT)
			img = data->tex->plr_right;
	}
	else
		return (1);
	mlx_put_image_to_window(data->mlx, data->win, img, w, h);
	return (0);
}

// translates and puts values in data->cords[2]
void	sl_translate_xy_to_pixel(t_sl_data *data, int x, int y)
{
	data->cords[0] = (x * TILE_WIDTH) + INDENT;
	data->cords[1] = (y * TILE_HEIGHT) + HEAD;
}
