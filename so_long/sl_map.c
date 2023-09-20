/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:17:19 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/20 17:45:49 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns 1 if c can't be found, updates x-y
// starts at [1][1]
int	sl_search_map(t_sl_data *data, char c, int *x, int *y)
{
	*y = 1;
	while (data->map[*y])
	{
		*x = 1;
		while (data->map[*y][*x])
		{
			if (data->map[*y][*x] == c)
				return (0);
			(*x)++;
		}
		(*y)++;
	}
	return (1);
}

int	sl_render_map(t_sl_data *data)
{
	int	x;
	int	y;

	data->cords[0] = 0;
	data->cords[1] = 0;
	sl_print_rectangle(data, data->win_w, data->win_h, BG_COL);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			sl_print_tile(data, x, y, 0);
			x++;
		}
		y++;
	}
	return (0);
}

static char	**sl_create_mask(t_sl_data *data)
{
	char	**new;
	int		i;
	int		j;

	new = malloc (sizeof(char *) * (data->map_h + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < data->map_h)
	{
		new[i] = malloc ((data->map_w + 1) * sizeof(char));
		if (!new[i])
			return (ft_clear_da(new));
		j = 0;
		while (j < data->map_w)
		{
			new[i][j] = EMPTY;
			j++;
		}
		new[i][j] = 0;
		i++;
	}
	new[i] = NULL;
	return (new);
}

// returns 1 if malloc (mask) failed ((or 'P' isn't found somehow))
int	sl_init_map(t_sl_data *data)
{
	data->mask_cr = sl_create_mask(data);
	if (!data->mask_cr)
	{
		perror("mask malloc");
		return (1);
	}
	if (sl_search_map(data, PLAYER, &data->plr[0], &data->plr[1]))
		return (1);
	data->map[data->plr[1]][data->plr[0]] = EMPTY;
	data->plr[2] = FACE_FRONT;
	data->plr_size = 16;
	data->mvs = 0;
	data->clbls = 0;
	sl_render_map(data);
	sl_print_game_frame(data, COL_WHITE);
	sl_print_reset(data);
	sl_print_midtext(data, NULL, -1, 0);
	sl_print_mvs(data);
	sl_print_clbl(data);
	return (0);
}
