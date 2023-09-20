/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_end_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:18:20 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/20 13:40:33 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_put_victory_screen(t_sl_data *data)
{
	char	*msg;
	char	*bin1;
	char	*bin2;

	sl_print_fullwin(data, data->end[0], 0, NULL);
	sl_print_midtext(data, "VICTORY!", data->win_h / 2 - 44, COL_WHITE);
	sl_print_midtext(data, "   exit  ", data->cords[1], COL_WHITE);
	sl_print_midtext(data, "   replay", data->cords[1] + 24, COL_WHITE);
	mlx_string_put(data->mlx, data->win, data->cords[0],
		data->cords[1], COL_WHITE, "->");
	if (data->win_w < 600)
		return ;
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
}

static void	sl_put_death_screen(t_sl_data *data)
{
	char	*msg;
	char	*bin1;
	char	*bin2;

	sl_print_fullwin(data, data->end[0], 0, NULL);
	sl_print_midtext(data, "YOU DIED!", data->win_h / 2 - 44, COL_WHITE);
	sl_print_midtext(data, "   exit ", data->cords[1], COL_WHITE);
	sl_print_midtext(data, "   retry", data->cords[1] + 24, COL_WHITE);
	mlx_string_put(data->mlx, data->win, data->cords[0],
		data->cords[1], COL_WHITE, "->");
	if (data->win_w < 600)
		return ;
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
}

static int	sl_end_hook(int key, t_sl_data *data)
{
	if (key == KEY_ESC)
		sl_flush_loop(data);
	else if (key == KEY_W || key == KEY_UP)
	{
		data->end[1] = 1;
		sl_print_rectangle(data, 20, 46, data->end[0]);
		mlx_string_put(data->mlx, data->win, data->cords[0],
			data->cords[1], COL_WHITE, "->");
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		data->end[1] = 2;
		sl_print_rectangle(data, 20, 46, data->end[0]);
		mlx_string_put(data->mlx, data->win, data->cords[0],
			data->cords[1] + 24, COL_WHITE, "->");
	}
	else if (key == KEY_SPC || key == KEY_ENTR)
	{
		if (data->end[1] == 1)
			sl_flush_loop(data);
		if (data->end[1] == 2)
			sl_reset(data);
	}
	return (0);
}

void	sl_victory_screen(t_sl_data *data)
{
	data->end[0] = VICS_COL;
	data->end[1] = 1;
	data->cords[0] = data->win_w / 2 - 45;
	data->cords[1] = data->win_h / 2 + 8;
	mlx_key_hook(data->win, sl_end_hook, (void *) data);
	mlx_loop_hook(data->mlx, sl_limp_loop, (void *) data);
	sl_put_victory_screen(data);
}

void	sl_death_screen(t_sl_data *data)
{
	data->end[0] = COL_DRED;
	data->end[1] = 1;
	data->cords[0] = data->win_w / 2 - 40;
	data->cords[1] = data->win_h / 2 + 8;
	mlx_key_hook(data->win, sl_end_hook, (void *) data);
	mlx_loop_hook(data->mlx, sl_limp_loop, (void *) data);
	sl_put_death_screen(data);
}
