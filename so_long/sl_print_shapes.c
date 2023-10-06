/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_shapes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:35:34 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/06 16:13:12 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// cords provided in data->cords[2]:[x,y] | resets them after use
// framewidth specified in -0000, total width in 0----
void	sl_print_frame(t_sl_data *data, int w, int h, int color)
{
	int	x;
	int	y;

	x = data->cords[0];
	y = data->cords[1];
	sl_print_rectangle(data, w % 10000, w / 10000, color);
	data->cords[1] = y + (w / 10000);
	sl_print_rectangle(data, w / 10000, h - 2 * (w / 10000), color);
	data->cords[0] = x + (w % 10000 - w / 10000);
	sl_print_rectangle(data, w / 10000, h - 2 * (w / 10000), color);
	data->cords[0] = x;
	data->cords[1] = y + (h - w / 10000);
	sl_print_rectangle(data, w % 10000, w / 10000, color);
	data->cords[1] = y;
}

// cords provided in data->cords[2]:[x,y]
void	sl_print_rectangle(t_sl_data *data, int w, int h, int color)
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
}
