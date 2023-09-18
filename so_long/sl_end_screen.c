/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_end_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:18:20 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/18 17:16:55 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_put_victory_screen(t_sl_data *data)
{
	char	msg;
	char	bin1;
	char	bin2;

	sl_print_fullwin(data, data->plr[0], 0, NULL);
	sl_print_midtext(data, "VICTORY!", data->win_h / 2 - 44, COL_COPPER);
	bin1 = ft_itoa(data->mvs);
	msg = ft_strjoin("You completed the level in ", bin1);
	free(bin1);
	bin1 = ft_strjoin(msg, " moves, finding ");
	free(msg);
	msg = ft_itoa(data->clbls);
	bin2 = ft_strjoin(bin1, msg);
	free(msg);
	free(bin1);
	msg = ft_strjoin(bin2, " collectibles.");
	free(bin2);
	sl_print_midtext(data, msg, data->win_h / 2 - 20, COL_WHITE);
	free(msg);
	sl_print_midtext(data, "   exit  ", data->cords[1], COL_WHITE);
	sl_print_midtext(data, "   replay", data->cords[1] + 24, COL_WHITE);
	mlx_string_put(data->mlx, data->win, data->cords[0],
		data->cords[1], COL_WHITE, "->");
}

static void	sl_put_death_screen(t_sl_data *data)
{
	char	msg;
	char	bin1;
	char	bin2;

	sl_print_fullwin(data, data->plr[0], 0, NULL);
	sl_print_midtext(data, "YOU DIED!", data->win_h / 2 - 44, COL_COPPER);
	bin1 = ft_itoa(data->mvs);
	msg = ft_strjoin("You made ", bin1);
	free(bin1);
	bin1 = ft_strjoin(msg, " moves, finding ");
	free(msg);
	msg = ft_itoa(data->clbls);
	bin2 = ft_strjoin(bin1, msg);
	free(msg);
	free(bin1);
	msg = ft_strjoin(bin2, " collectibles.");
	free(bin2);
	sl_print_midtext(data, msg, data->win_h / 2 - 20, COL_WHITE);
	free(msg);
	sl_print_midtext(data, "   exit ", data->cords[1], COL_WHITE);
	sl_print_midtext(data, "   retry", data->cords[1] + 24, COL_WHITE);
	mlx_string_put(data->mlx, data->win, data->cords[0],
		data->cords[1], COL_WHITE, "->");
}

static void	sl_end_hook(int key, t_sl_data *data)
{
	if (key == KEY_ESC)
		sl_flush_loop(data);
	else if (key == KEY_W || key == KEY_UP)
	{
		data->plr[2] == 1;
		sl_print_rectangle(data, 20, 46, data->plr[0]);
		mlx_string_put(data->mlx, data->win, data->cords[0],
			data->cords[1], COL_WHITE, "->");
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		data->plr[2] == 2;
		sl_print_rectangle(data, 20, 46, data->plr[0]);
		mlx_string_put(data->mlx, data->win, data->cords[0],
			data->cords[1] + 24, COL_WHITE, "->");
	}
	else if (key == KEY_SPC || key == KEY_ENTR)
	{
		if (data->plr[2] == 1)
			sl_flush_loop(data);
		if (data->plr[2] == 2)
			sl_reset(data);
	}
}

// overwrites data->plr to keep track of bg_col and selected option
void	sl_victory_screen(t_sl_data *data)
{
	data->plr[0] = sl_create_color(30, 150, 70);
	data->plr[2] = 1;
	data->cords[0] = data->win_w / 2 - 45;
	data->cords[1] = data->win_h / 2 + 8;
	sl_put_victory_screen(data);
	mlx_key_hook(data->win, sl_end_hook, (void *) data);
}

// overwrites data->plr to keep track of bg_col and selected option
void	sl_death_screen(t_sl_data *data)
{
	data->plr[0] = sl_create_color(150, 30, 30);
	data->plr[2] = 1;
	data->cords[0] = data->win_w / 2 - 40;
	data->cords[1] = data->win_h / 2 + 8;
	sl_put_death_screen(data);
	mlx_key_hook(data->win, sl_end_hook, (void *) data);
}
