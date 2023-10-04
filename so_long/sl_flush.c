/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_flush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:23:48 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/04 17:58:41 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// clears sprites, anims, map, mask_cr, data->crs
int	sl_flush_all(t_sl_data *data)
{
	sl_clear_sprs(data);
	sl_clear_animations(data);
	ft_clear_da(data->map);
	ft_clear_da(data->mask_cr);
	ft_lstclear(data->crs, free);
	return (0);
}

// exits
int	sl_flush_loop(t_sl_data *data)
{
	char	*level;

	level = malloc(sizeof(char) * (ft_strlen(data->map_file) - 8));
	ft_strlcpy(level, data->map_file + 5, ft_strlen(data->map_file) - 8);
	if (data->map[data->plr[1]][data->plr[0]] != EXIT_OPEN || !data->plr_size)
		ft_printf("quitting the game\n");
	else if (level)
		ft_printf("completed the level '%s' in %i moves\n", level, data->mvs);
	else
		ft_printf("completed the level in %i moves\n", data->mvs);
	if (level)
		free(level);
	sl_flush_all(data);
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

// returns 1 if sl_init_map failed
int	sl_reset(t_sl_data *data)
{
// check all this stuff for leaks too... (like data->map)
// and so i need to return or just call flush_loop?
	ft_clear_da(data->map);
	data->map = sl_create_map(data->map_file);
	if (!data->map)
		sl_flush_loop(data);
	ft_clear_da(data->mask_cr);
	data->mask_cr = NULL;
	ft_lstclear(data->crs, free);
	sl_shrink_plr(data, 1);
	if (sl_init_map(data))
		return (1);
	mlx_key_hook(data->win, sl_key_hook_hub, (void *) data);
	data->clock = 0;
	data->msgtimer = 0;
	data->immunetimer = 0;
	mlx_loop_hook(data->mlx, sl_timed_loop, (void *) data);
	return (0);
}
