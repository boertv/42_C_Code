/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:07:55 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/26 13:53:34 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_key_hook_hub(int key, t_sl_data *data)
{
	if (key == KEY_ESC)
		sl_flush_loop(data);
	else if (key == KEY_W || key == KEY_UP)
		sl_move_cr(data, NULL, NULL, DIR_UP);
	else if (key == KEY_A || key == KEY_LEFT)
		sl_move_cr(data, NULL, NULL, DIR_LEFT);
	else if (key == KEY_S || key == KEY_DOWN)
		sl_move_cr(data, NULL, NULL, DIR_DOWN);
	else if (key == KEY_D || key == KEY_RIGHT)
		sl_move_cr(data, NULL, NULL, DIR_RIGHT);
	else if (SL_CHEATS && key == KEY_C)
		data->clbls += 10;
	else if (SL_CHEATS && key == KEY_G)
		sl_grow_plr(data);
	else if (key == KEY_R)
	{
		if (sl_reset(data))
			sl_flush_loop(data);
	}
	else if (SL_CHEATS)
	{
		ft_printf("key not in use [%i]\n", key);
		return (1);
	}
	return (0);
}

static void	sl_plr_hitreg(t_sl_data *data)
{
	if (SL_CHEATS)
		return ;
	data->immunetimer = 200;
	if (sl_shrink_plr(data, 0))
	{
		sl_death_screen(data);
		return ;
	}
	sl_print_midtext(data, "You got hit!", -1, MSG_COL);
	data->msgtimer = 100;
}

static void	sl_print_clock(t_sl_data *data)
{
	char	*bin;
	int		ogx;
	int		ogy;

	if (HEAD < 55)
		return ;
	ogx = data->cords[0];
	ogy = data->cords[1];
	data->cords[0] = 0;
	data->cords[1] = 0;
	sl_print_rectangle(data, 70, 22, BG_COL);
	if (!data->immunetimer)
	{
		bin = ft_itoa(data->clock);
		mlx_string_put(data->mlx, data->win, 0, 0, UI_COL, bin);
	}
	else
	{
		bin = ft_itoa(data->immunetimer);
		mlx_string_put(data->mlx, data->win, 0, 0, COL_WHITE, bin);
	}
	free(bin);
	data->cords[0] = ogx;
	data->cords[1] = ogy;
}

int	sl_timed_loop(t_sl_data *data)
{
	data->clock++;
	if (data->clock >= 1000000000)
		data->clock = 0;
	sl_print_clock(data);
	if (data->clock % 50 == 0)
		sl_move_knights(data);
	if (data->msgtimer)
	{
		data->msgtimer--;
		if (!data->msgtimer)
			sl_print_midtext(data, NULL, -1, BG_COL);
	}
	if (data->immunetimer)
		data->immunetimer--;
	else
		if (data->mask_cr[data->plr[1]][data->plr[0]] != EMPTY)
			sl_plr_hitreg(data);
	return (0);
}

void	sl_mlx_loop(t_sl_data *data)
{
	data->clock = 0;
	data->msgtimer = 0;
	data->immunetimer = 0;
	mlx_key_hook(data->win, sl_key_hook_hub, (void *) data);
	mlx_hook(data->win, 17, 0, sl_flush_loop, (void *) data);
	mlx_loop_hook(data->mlx, sl_timed_loop, (void *) data);
	mlx_loop(data->mlx);
}
