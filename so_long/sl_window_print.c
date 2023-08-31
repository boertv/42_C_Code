/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_window_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:08:30 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/31 19:31:06 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//prints map and mask_cr
// if -1000 < offset < 1000 it is added to width, else the diff is to height
int	sl_print_tile(t_sl_data *data, int x, int y, int offset)
{
	void	*mlx;
	int		w;
	int		h;

	mlx = data->mlx;
	w = ((x * TILE_WIDTH) + INDENT)
		+ ((offset <= 1000 && -1000 <= offset) * offset);
	h = ((y * TILE_HEIGHT) + HEAD) + ((offset > 1000 || -1000 > offset)
			* (offset + (((offset >= 0) * -1000) + ((offset < 0) * 1000))));
	if (data->map[y][x] == WALL)
	{
		mlx_put_image_to_window(mlx, data->win, data->tex->wall, w, h);
		return (0);
	}
	mlx_put_image_to_window(mlx, data->win, data->tex->empty, w, h);
	if (data->map[y][x] == CLBL_NEW)
		mlx_put_image_to_window(mlx, data->win, data->tex->clbl_new, w, h);
	else if (data->map[y][x] == CLBL_OLD)
		mlx_put_image_to_window(mlx, data->win, data->tex->clbl_old, w, h);
	else if (data->map[y][x] == EXIT_CLSD)
		mlx_put_image_to_window(mlx, data->win, data->tex->exit_clsd, w, h);
	else if (data->map[y][x] == EXIT_OPEN)
		mlx_put_image_to_window(mlx, data->win, data->tex->exit_open, w, h);
	sl_print_mask_cr(data, x, y);
	return (0);
}

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
			mlx_pixel_put(data->mlx, data->win, data->cords[0] + i, data->cords[1] + j, color);
			i++;
		}
		j++;
	}
	return (0);
}

void	sl_print_mvs(t_sl_data *data)
{
	if (HEAD >= 30)
	{
		data->cords[0] = 5 + INDENT;
		data->cords[1] = HEAD - 23;
		sl_print_rectangle(data, 32, 20, sl_create_color(0, 0, 0, 0));
		mlx_string_put(data->mlx, data->win, data->cords[0], data->cords[1], sl_create_color(0, 250, 250, 250), ft_itoa(data->mvs));
		return ;
	}
	data->cords[0] = 5 + INDENT;
	data->cords [1] = 3 + HEAD;
	sl_print_tile(data, 0, 0, 0);
	sl_print_tile(data, 1, 0, 0);
//transparency dont work
	mlx_string_put(data->mlx, data->win, data->cords[0], data->cords[1], sl_create_color(0, 250, 250, 250), ft_itoa(data->mvs));
}
