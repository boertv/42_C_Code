/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:07:55 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/31 16:37:21 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_key_hook_hub(int key, t_sl_data *data)
{
	if (key == KEY_ESC)
		sl_flush_loop(data);
	else if (key == KEY_W)
		sl_move_cr(data, &data->plr[0], &data->plr[1], DIR_UP);
	else if (key == KEY_A)
		sl_move_cr(data, &data->plr[0], &data->plr[1], DIR_LEFT);
	else if (key == KEY_S)
		sl_move_cr(data, &data->plr[0], &data->plr[1], DIR_DOWN);
	else if (key == KEY_D)
		sl_move_cr(data, &data->plr[0], &data->plr[1], DIR_RIGHT);
	else
	{
		ft_printf("key not in use [%i]\n", key);
		return (1);
	}
	return (0);
}

void	sl_mlx_loop(t_sl_data *data)
{
	mlx_key_hook(data->win, sl_key_hook_hub, (void *) data);
	mlx_hook(data->win, 17, 0, sl_flush_loop, (void *) data);
	mlx_loop(data->mlx);
}
