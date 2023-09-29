/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_timed_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:15:15 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/29 14:22:41 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_plr_hit(t_sl_data *data)
{
	if (SL_CHEATS)
		return ;
	data->immunetimer = SL_IMMUNETMR;
	if (sl_shrink_plr(data, 0))
	{
		sl_death_screen(data);
		return ;
	}
	sl_print_fullwin(data, COL_DRED, 0, NULL);
}

static void	sl_hitreg(t_sl_data *data)
{
	if (data->immunetimer)
	{
		if (data->immunetimer == SL_IMMUNETMR)
			sl_render_map(data);
		data->immunetimer--;
	}
	else
		if (data->mask_cr[data->plr[1]][data->plr[0]] != EMPTY)
			sl_plr_hit(data);
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
		lst = lst->next;
	}
}

int	sl_timed_loop(t_sl_data *data)
{
	data->clock++;
	if (data->clock >= 1000000000)
		data->clock = 0;
	sl_print_clock(data);
	if (data->clock % SL_ANIM_BUFF == 0)
		sl_animate_crs(data);
	if (data->clock % MV_TIME_CR == 0)
		sl_move_crs(data);
	if (data->msgtimer)
	{
		data->msgtimer--;
		if (!data->msgtimer)
			sl_print_midtext(data, NULL, -1, BG_COL);
	}
	sl_hitreg(data);
	return (0);
}
