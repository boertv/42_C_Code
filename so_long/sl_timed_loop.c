/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_timed_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:15:15 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/04 17:56:21 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns 1 if player got hit
int	sl_hitreg(t_sl_data *data)
{
	if (data->immunetimer || SL_CHEATS)
		return (0);
	if (ft_strchr(CR_CHARS_UPC, data->mask_cr[data->plr[1]][data->plr[0]]))
	{
		if (sl_shrink_plr(data, 0))
		{
			sl_death_screen(data);
			return (1);
		}
		data->immunetimer = SL_IMMUNETMR;
		sl_print_fullwin(data, COL_DRED, 0, NULL);
		return (1);
	}
	return (0);
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

static void	sl_animate_crs(t_sl_data *data)
{
	t_list	*lst;

	lst = *data->crs;
	while (lst)
	{
		sl_advance_am(data, lst->content);
		if (!data->plr_size)
			return ;
		lst = lst->next;
	}
}

int	sl_timed_loop(t_sl_data *data)
{
	if (data->immunetimer)
	{
		if (data->immunetimer == SL_IMMUNETMR)
			sl_render_map(data);
		data->immunetimer--;
	}
	data->clock++;
	if (data->clock >= 1000000000)
		data->clock = 0;
	sl_print_clock(data);
	if (data->clock % SL_ANIM_BUFF == 0)
		sl_animate_crs(data);
	if (data->plr_size && data->clock % MV_TIME_CR == 0)
		sl_move_crs(data);
	if (data->plr_size && data->msgtimer)
	{
		data->msgtimer--;
		if (!data->msgtimer)
			sl_print_midtext(data, NULL, -1, BG_COL);
	}
	return (0);
}
