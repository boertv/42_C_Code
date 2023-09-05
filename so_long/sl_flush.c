/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_flush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:23:48 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/05 16:12:12 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// clears sprites, map, mask_cr
int	sl_flush_all(t_sl_data *data)
{
	sl_clear_sprs(data);
	ft_clear_da(data->map);
	ft_clear_da(data->mask_cr);
	return (0);
}

// exits
int	sl_flush_loop(t_sl_data *data)
{
	if (data->map[data->plr[1]][data->plr[0]] != EXIT_OPEN)
		ft_printf("quitting the game\n");
	else
		ft_printf("completed the level in %i moves\n", data->mvs);
	sl_flush_all(data);
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

// returns 1 if sl_init_map failed
int	sl_reset(t_sl_data *data)
{
	ft_clear_da(data->map);
	ft_clear_da(data->mask_cr);
	data->map = sl_create_map(data->map_file);
	if (sl_init_map(data))
		return (1);
	return (0);
}
