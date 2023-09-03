/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_window_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:08:30 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/03 21:19:21 by bvercaem         ###   ########.fr       */
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

void	sl_print_mvs(t_sl_data *data)
{
	char	*temp;

	temp = ft_itoa(data->mvs);
	if (HEAD >= 25)
	{
		data->cords[0] = 5 + INDENT;
		data->cords[1] = HEAD - 23;
		sl_print_rectangle(data, 32, 22, sl_create_color(0, 0, 0));
		mlx_string_put(data->mlx, data->win, data->cords[0], data->cords[1],
			sl_create_color(255, 255, 255), temp);
		free(temp);
		return ;
	}
	sl_print_tile(data, 0, 0, 0);
	sl_print_tile(data, 1, 0, 0);
	mlx_string_put(data->mlx, data->win, INDENT + 5, HEAD + 2,
		sl_create_color(255, 255, 255), temp);
	free(temp);
}

// these need to be done in one ft so i can properly clear the background first (tiles are too large for this)
void	sl_print_clbl(t_sl_data *data)
{
	char	*print;

	if (data->map_w < 5)
		return ;
	print = ft_itoa(data->clblt);
	if (HEAD >= 25)
	{
		data->cords[0] = (data->win_w / 2) - 32;
		data->cords[1] = HEAD - 23;
		sl_print_rectangle(data, 72, 22, sl_create_color(255, 0, 0));
		sl_print_midtext(data, "/", HEAD - 23, sl_create_color(255, 255, 255));
		mlx_string_put(data->mlx, data->win, (data->win_w / 2) + 6, HEAD - 22, sl_create_color(255, 255, 255), print);
		free(print);
		print = ft_itoa(data->clbls);
		mlx_string_put(data->mlx, data->win, (data->win_w / 2) - 16, HEAD - 22, sl_create_color(255, 255, 255), print);
		free(print);
		return ;
	}
	sl_print_tile(data, data->map_w / 2 - 1, 0, 0);
	sl_print_tile(data, data->map_w / 2, 0, 0);
	sl_print_tile(data, data->map_w / 2 + 1, 0, 0);
	sl_print_midtext(data, "/", HEAD + 1, sl_create_color(255, 255, 255));
	mlx_string_put(data->mlx, data->win, (data->win_w / 2) + 6, HEAD + 2, sl_create_color(255, 255, 255), print);
	free(print);
	print = ft_itoa(data->clbls);
	mlx_string_put(data->mlx, data->win, (data->win_w / 2) - 16, HEAD + 2, sl_create_color(255, 255, 255), print);
	free(print);
}

// void	sl_print_clbls(t_sl_data *data)
// {
// 	char	*print;

// 	if (data->map_w < 5)
// 		return ;
// 	print = ft_itoa(data->clbls);
// 	if (HEAD >= 25)
// 	{
// 		data->cords[0] = (data->win_w / 2) - 32;
// 		data->cords[1] = HEAD - 23;
// 		sl_print_rectangle(data, 26, 22, 0);
// 		mlx_string_put(data->mlx, data->win, (data->win_w / 2) - 16, HEAD - 22, sl_create_color(255, 255, 255), print);
// 		free(print);
// 		return ;
// 	}
// 	// sl_print_tile(data, data->map_w / 2 - 1, 0, 0);
// 	// sl_print_tile(data, data->map_w / 2, 0, 0);
// 	// sl_print_tile(data, data->map_w / 2 + 1, 0, 0);
// 	sl_print_midtext(data, "/", HEAD + 1, sl_create_color(255, 255, 255));
// 	mlx_string_put(data->mlx, data->win, (data->win_w / 2) - 16, HEAD + 2, sl_create_color(255, 255, 255), print);
// 	free(print);
// }
