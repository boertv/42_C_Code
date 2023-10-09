/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hitreg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:21:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/09 16:41:58 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_undo_hit_indicator(t_sl_data *data)
{
	if (SL_HIT_IND == 1)
		sl_render_map(data);
	if (SL_HIT_IND == 2)
		sl_print_tile(data, data->plr[0], data->plr[1], 0);
}

static void	sl_hit_indicator(t_sl_data *data)
{
	if (!SL_HIT_IND)
	{
		sl_print_midtext(data, "You got hit!", -1, MSG_COL);
		data->msgtimer = 100;
	}
	if (SL_HIT_IND == 1)
	{
		if (data->map[data->plr[1]][data->plr[0]] != EXIT_OPEN)
			sl_print_fullwin(data, COL_DRED, 0, NULL);
	}
	if (SL_HIT_IND == 2)
	{
		data->cords[0] = sl_cv_cdpx(data->plr[0], 'x', 0) + 1;
		data->cords[1] = sl_cv_cdpx(data->plr[1], 'y', 0) + 1;
		sl_print_rectangle(data, TILE_WIDTH - 2, TILE_HEIGHT - 2, COL_DRED);
	}
}

// returns 1 if player got hit
int	sl_hitreg(t_sl_data *data)
{
	if (data->munetmr || SL_CHEATS)
		return (0);
	if (ft_strchr(CR_CHARS_UPC, data->mask_cr[data->plr[1]][data->plr[0]]))
	{
		if (sl_shrink_plr(data, 0))
		{
			sl_death_screen(data);
			return (1);
		}
		data->munetmr = SL_IMMUNITY;
		sl_hit_indicator(data);
		return (1);
	}
	return (0);
}
