/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:25:32 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/28 19:37:27 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_bounce(t_sl_data *data, t_creature *cr)
{
	if (cr->dir[cr->dir_i] == DIR_RIGHT)
		sl_cr_dir_next(data, sl_search_cr_xy(data, cr->cd[0] + 1, cr->cd[1]));
	if (cr->dir[cr->dir_i] == DIR_LEFT)
		sl_cr_dir_next(data, sl_search_cr_xy(data, cr->cd[0] - 1, cr->cd[1]));
}

static void	sl_start_anim(t_sl_data *data, t_creature *cr)
{
	if (cr->type == KNIGHT)
	{
		if (cr->dir[cr->dir_i] == DIR_LEFT)
		{
			cr->frame = *data->am->k_mv_l;
			cr->offset = OFF_K_START;
		}
		else
		{
			cr->frame = *data->am->k_mv_r;
			cr->offset = OFF_K_START * -1;
		}
	}
	sl_print_amframe(data, cr);
}

static int	sl_moving_knight(t_sl_data *data, t_creature *cr)
{
	int	check;

	check = sl_move_cr(data, &cr->cd[0], &cr->cd[1], cr->dir[cr->dir_i]);
	if (!check)
		sl_start_anim(data, cr);
	if (check == 2)
		sl_bounce(data, cr);
	if (check)
	{
		sl_cr_dir_next(data, cr);
		sl_print_tile(data, cr->cd[0], cr->cd[1], 0);
	}
	return (1);
}

void	sl_move_crs(t_sl_data *data)
{
	t_list	*lst;

	lst = *(data->crs);
	while (lst)
	{
		lst = lst->next;
	}
}
