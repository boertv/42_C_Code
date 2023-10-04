/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:20:18 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/04 17:06:33 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sl_create_win(t_sl_data *data)
{
	data->win_w = (data->map_w * TILE_WIDTH) + SHOLDR + INDENT;
	data->win_h = (data->map_h * TILE_HEIGHT) + HEAD + TAIL;
	data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, SL_NAME);
	if (!data->win)
	{
		ft_printf("%fdmlx window creation failed\n", 2);
		return (1);
	}
	return (0);
}

// returns 1 if something failed
int	sl_mlx_init(t_sl_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("%fdmlx initialization failed\n", 2);
		return (1);
	}
	if (sl_create_win(data))
		return (1);
	return (0);
}
