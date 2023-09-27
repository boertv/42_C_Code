/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:35:03 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/26 17:50:39 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// takes values between 0 - 255
int	sl_create_color(int t, int r, int g, int b)
{
	if (t < 0 || t > 255 || r < 0 || r > 255
		|| g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	return (t << 24 | r << 16 | g << 8 | b);
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

	if (y == -1)
	{
		if (TAIL >= 25)
		{
			data->cords[0] = INDENT;
			data->cords[1] = data->win_h - TAIL + 1;
			sl_print_rectangle(data, data->win_w - INDENT - SHOULDER, 23, BG_COL);
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
	x = ft_strlen(str);
	if (!str || (int) (x * 10) >= (data->win_w - INDENT - SHOULDER))
		return ;
	x = (data->win_w / 2) - ((x * 10) / 2);
	mlx_string_put(data->mlx, data->win, x, y, color, str);
}

// 'xy' indicates what coordinate is being converted
int	sl_cv_cdpx(int cord, char xy, int offset)
{
	if (xy == 'x')
	{
		return (((cord * TILE_WIDTH) + INDENT)
			+ ((offset <= 1000 && -1000 <= offset) * offset));
	}
	if (xy == 'y')
	{
		return (((cord * TILE_HEIGHT) + HEAD)
			+ ((offset > 1000 || -1000 > offset)
				* (offset + (((offset >= 0) * -1000)
						+ ((offset < 0) * 1000)))));
	}
	return (0);
}

// img is put at [w][h] and [w + TLS][h + TLS] depending on which is -
// if both are negative, it prints all four. if none are -, it prints just one
void	sl_put_imgs_tile(t_sl_data *data, int w, int h, void *img)
{
	int	ah;
	int	aw;

	ah = h;
	if (ah < 0)
		ah *= -1;
	aw = w;
	if (aw < 0)
		aw *= -1;
	if (w < 0 && h < 0)
		mlx_put_image_to_window(data->mlx, data->win, img, aw + TLS, ah + TLS);
	mlx_put_image_to_window(data->mlx, data->win, img, aw, ah);
	if (w < 0)
		mlx_put_image_to_window(data->mlx, data->win, img, aw + TLS, ah);
	if (h < 0)
		mlx_put_image_to_window(data->mlx, data->win, img, aw, ah + TLS);
}
