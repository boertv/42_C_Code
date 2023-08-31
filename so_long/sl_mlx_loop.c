/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:07:55 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/31 14:34:16 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_key_hook_hub(int key, t_sl_data *data)
{
	if (key == KEY_ESC)
	{
		sl_flush_loop(data);
		exit (0);
	}
	ft_printf("key not in use [%i]\n", key);
	return (1);
}

void	sl_mlx_loop(t_sl_data *data)
{
	mlx_key_hook(data->win, sl_key_hook_hub, (void *) data);
	mlx_loop(data->mlx);
}
