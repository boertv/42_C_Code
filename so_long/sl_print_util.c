/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:35:03 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/01 18:59:32 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// cords provided in data->cords[2]
int	sl_print_rectangle(t_sl_data *data, int w, int h, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			mlx_pixel_put(data->mlx, data->win,
				data->cords[0] + i, data->cords[1] + j, color);
			i++;
		}
		j++;
	}
	return (0);
}

// takes values between 0 - 255
int	sl_create_color(int r, int g, int b)
{
	if (r < 0 || r > 255
		|| g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	return (r << 16 | g << 8 | b);
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

// if y == -1, text is printed at the bottom
// if str == NULL, text is cleared
void	sl_print_midtext(t_sl_data *data, char *str, int y, int color)
{
	size_t	x;
	int		i;

	x = ft_strlen(str);
	x = (data->win_w / 2) - ((x * 10) / 2);
	if (y == -1)
	{
		if (TAIL >= 25)
		{
			data->cords[0] = 0;
			data->cords[1] = data->win_h - TAIL + 1;
			sl_print_rectangle(data, data->win_w, TAIL - 1, 0);
			y = data->win_h - TAIL + 2;
		}
		else
		{
			i = data->map_w;
			while (i--)
				sl_print_tile(data, i, data->map_h - 1, 0);
			y = data->win_h - TAIL - 29;
		}
	}
	if (str)
		mlx_string_put(data->mlx, data->win, x, y, color, str);
}
