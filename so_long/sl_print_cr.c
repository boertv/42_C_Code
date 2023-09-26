/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_cr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:21:41 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/26 16:54:36 by bvercaem         ###   ########.fr       */
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

static void	sl_print_cr(t_sl_data *data, int w, int h, char cr)
{
	void	*img;

	img = NULL;
	if (cr == KNIGHT_L)
		img = data->tex->knight_l;
	if (cr == KNIGHT_R)
		img = data->tex->knight_r;
	mlx_put_image_to_window(data->mlx, data->win, img, w, h);
}

// prints the cr and/or player on [x][y]
int	sl_print_mask_cr(t_sl_data *data, int x, int y)
{
	int		w;
	int		h;

	w = sl_cv_cdpx(x, 'x', 0);
	h = sl_cv_cdpx(y, 'y', 0);
	if (data->mask_cr[y][x] != '0')
		sl_print_cr(data, w, h, data->mask_cr[y][x]);
	if (data->plr[0] == x && data->plr[1] == y)
		sl_print_plr(data, w, h);
	else
		return (1);
	return (0);
}
