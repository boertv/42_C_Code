/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_end_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:18:20 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/20 15:40:00 by bvercaem         ###   ########.fr       */
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

void	sl_victory_screen(t_sl_data *data)
{
	data->end[0] = VICS_COL;
	data->end[1] = 1;
	data->cords[0] = data->win_w / 2 - 40;
	data->cords[1] = data->win_h / 2 + 8;
	mlx_key_hook(data->win, sl_end_hook, (void *) data);
	data->time = 0;
	mlx_loop_hook(data->mlx, sl_end_loop, (void *) data);
	sl_put_victory_screen(data);
	data->cords[1] += 4;
	sl_put_answer_indicator(data, data->end[1]);
}

void	sl_death_screen(t_sl_data *data)
{
	data->end[0] = COL_DRED;
	data->end[1] = 1;
	data->cords[0] = data->win_w / 2 - 40;
	data->cords[1] = data->win_h / 2 + 8;
	mlx_key_hook(data->win, sl_end_hook, (void *) data);
	data->time = 0;
	mlx_loop_hook(data->mlx, sl_end_loop, (void *) data);
	sl_put_death_screen(data);
	data->cords[1] += 4;
	sl_put_answer_indicator(data, data->end[1]);
}
