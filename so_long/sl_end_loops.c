/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_end_loops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:11:07 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/20 15:56:15 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_put_answer_indicator(t_sl_data *data, int item)
{
	sl_print_rectangle(data, 14, 14, COL_BLACK);
	data->cords[1] += 24;
	sl_print_rectangle(data, 14, 14, COL_BLACK);
	data->cords[1] -= 24;
	data->cords[0] += 2;
	data->cords[1] += 2 + ((item - 1) * (24));
	sl_print_rectangle(data, 10, 10, UI_COL);
	data->cords[0] -= 2;
	data->cords[1] -= 2 + ((item - 1) * (24));
}

int	sl_end_hook(int key, t_sl_data *data)
{
	if (key == KEY_ESC)
		sl_flush_loop(data);
	if (key == KEY_SPC || key == KEY_ENTR)
	{
		if (data->end[1] == 1)
			sl_flush_loop(data);
		if (data->end[1] == 2)
			sl_reset(data);
	}
	if (key == KEY_W || key == KEY_UP)
		data->end[1] = 1;
	if (key == KEY_S || key == KEY_DOWN)
		data->end[1] = 2;
	if (key == KEY_W || key == KEY_UP || key == KEY_S || key == KEY_DOWN)
		sl_put_answer_indicator(data, data->end[1]);
	return (0);
}

// doesn't do anything rn, also seems to loop way faster than timed_loop
int	sl_end_loop(t_sl_data *data)
{
	data->clock++;
	if (data->clock >= 1000000)
		data->clock = 0;
	return (0);
}
