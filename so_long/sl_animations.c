/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:31:04 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/05 17:31:34 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_print_am_frame(t_sl_data *data, t_creature *cr)
{
	int	w;
	int	h;

	w = sl_cv_cdpx(cr->cd[0], 'x', cr->offset);
	h = sl_cv_cdpx(cr->cd[1], 'y', cr->offset);
	sl_print_tile(data, cr->cd[0], cr->cd[1], 0);
	sl_print_tile(data, cr->cd[0] + (cr->dir[cr->dir_i] == DIR_LEFT)
		- (cr->dir[cr->dir_i] == DIR_RIGHT), cr->cd[1]
		+ (cr->dir[cr->dir_i] == DIR_UP) - (cr->dir[cr->dir_i] == DIR_DOWN), 0);
	mlx_put_image_to_window(data->mlx, data->win, cr->frame->content, w, h);
}

// prints the next frame in the anim and increments or ends it
void	sl_advance_am(t_sl_data *data, t_creature *cr)
{
	if (!cr->frame)
		return ;
	cr->frame = cr->frame->next;
	if (!cr->frame)
	{
		cr->offset = 0;
		if (sl_cr_advance_tile(data, cr) == 2)
			return ;
		sl_print_tile(data, cr->cd[0], cr->cd[1], 0);
		sl_print_tile(data, cr->cd[0] + (cr->dir[cr->dir_i] == DIR_LEFT)
			- (cr->dir[cr->dir_i] == DIR_RIGHT), cr->cd[1]
			+ (cr->dir[cr->dir_i] == DIR_UP)
			- (cr->dir[cr->dir_i] == DIR_DOWN), 0);
		return ;
	}
	if (cr->type == KNIGHT)
	{
		if (cr->dir[cr->dir_i] == DIR_LEFT)
			cr->offset -= OFF_K_INC;
		else
			cr->offset += OFF_K_INC;
	}
	if (sl_cr_advance_tile(data, cr) == 2)
		return ;
	sl_print_am_frame(data, cr);
}
