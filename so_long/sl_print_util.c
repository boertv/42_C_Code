/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:35:03 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/14 17:21:56 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// takes values between 0 - 255
int	sl_create_color(int r, int g, int b)
{
	if (r < 0 || r > 255
		|| g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	return (r << 16 | g << 8 | b);
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
			data->cords[0] = INDENT;
			data->cords[1] = data->win_h - TAIL + 1;
			sl_print_rectangle(data, data->win_w - INDENT - HEAD, 23, 0);
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