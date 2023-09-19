/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_window_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:08:30 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/19 18:07:12 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_print_mvs(t_sl_data *data)
{
	char	*temp;

	temp = ft_itoa(data->mvs);
	if (HEAD >= 25)
	{
		data->cords[0] = 5 + INDENT;
		data->cords[1] = HEAD - 23;
		sl_print_rectangle(data, 32, 22, BG_COL);
		mlx_string_put(data->mlx, data->win, data->cords[0], data->cords[1],
			COL_COPPER, temp);
		free(temp);
		return ;
	}
	sl_print_tile(data, 0, 0, 0);
	sl_print_tile(data, 1, 0, 0);
	mlx_string_put(data->mlx, data->win, INDENT + 5, HEAD + 2,
		COL_BLACK, temp);
	free(temp);
}

// fills screen with bgcol and prints msg in txcol
// if msg == NULL only full window in bgcol is printed
void	sl_print_fullwin(t_sl_data *data, int bgcol, int txcol, char *msg)
{
	int	x;
	int	y;

	x = data->cords[0];
	y = data->cords[1];
	data->cords[0] = 0;
	data->cords[1] = 0;
	sl_print_rectangle(data, data->win_w, data->win_h, bgcol);
	if (msg)
		sl_print_midtext(data, msg, (data->win_h / 2) - 10, txcol);
	data->cords[0] = x;
	data->cords[1] = y;
}

void	sl_print_reset(t_sl_data *data)
{
	if (HEAD < 25)
		return ;
	if (data->map_w > 10)
	{
		data->cords[0] = data->win_w - SHOULDER - 2 - (10 * 9);
		data->cords[1] = HEAD - 22;
		sl_print_rectangle(data, 2 + (10 * 9), 22, BG_COL);
		mlx_string_put(data->mlx, data->win, data->win_w - SHOULDER
			- 2 - (10 * 9), HEAD - 22, COL_COPPER, "reset 'r'");
		return ;
	}
	data->cords[0] = data->win_w - SHOULDER - 2 - (10 * 3);
	data->cords[1] = HEAD - 22;
	sl_print_rectangle(data, 2 + (10 * 3), 22, BG_COL);
	mlx_string_put(data->mlx, data->win, data->win_w - SHOULDER - 2 - (10 * 3),
		HEAD - 22, COL_COPPER, "'r'");
}

void	sl_print_game_frame(t_sl_data *data, int color)
{
	if (HEAD < 33 || TAIL < 33 || INDENT < 8 || SHOULDER < 8)
		return ;
	data->cords[0] = INDENT - 8;
	data->cords[1] = HEAD - 31;
	sl_print_frame(data, 50016 + data->win_w - SHOULDER - INDENT,
		62 + data->win_h - HEAD - TAIL, color);
}
