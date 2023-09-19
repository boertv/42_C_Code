/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_clbl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:42:43 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/19 18:11:16 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_print_clbl_head(t_sl_data *data)
{
	char	*print;

	print = ft_itoa(data->clblt);
	data->cords[0] = (data->win_w / 2) - 38;
	data->cords[1] = HEAD - 23;
	sl_print_rectangle(data, 78, 21, BG_COL);
	sl_print_frame(data, 20078, 21, COL_COPPER);
	data->cords[0] += 2;
	data->cords[1] += 2;
	sl_print_rectangle(data, (74 * data->clbls) / data->clblt,
		17, sl_create_color(150, 50, 50));
	if (data->clbls && data->clbls < data->clblt)
	{
		if ((74 * data->clbls) / data->clblt > 0)
			data->cords[0] += ((74 * data->clbls) / data->clblt) - 1;
		sl_print_rectangle(data, 2, 17, COL_WHITE);
	}
	sl_print_midtext(data, "/", HEAD - 25, COL_COPPER);
	mlx_string_put(data->mlx, data->win, (data->win_w / 2) + 6,
		HEAD - 24, COL_COPPER, print);
	free(print);
	print = ft_itoa(data->clbls);
	mlx_string_put(data->mlx, data->win, (data->win_w / 2)
		- (6 + (ft_strlen(print) * 10)), HEAD - 24, COL_COPPER, print);
	free(print);
}

static void	sl_print_clbl_nohead(t_sl_data *data)
{
	char	*print;

	print = ft_itoa(data->clblt);
	sl_print_tile(data, data->map_w / 2 - 1, 0, 0);
	sl_print_tile(data, data->map_w / 2, 0, 0);
	sl_print_tile(data, data->map_w / 2 + 1, 0, 0);
	sl_print_midtext(data, "/", HEAD + 1, COL_BLACK);
	mlx_string_put(data->mlx, data->win, (data->win_w / 2) + 6,
		HEAD + 2, COL_BLACK, print);
	free(print);
	print = ft_itoa(data->clbls);
	mlx_string_put(data->mlx, data->win, (data->win_w / 2)
		- (6 + (ft_strlen(print) * 10)), HEAD + 2, COL_BLACK, print);
	free(print);
}

void	sl_print_clbl(t_sl_data *data)
{
	if (data->map_w < 5)
		return ;
	if (HEAD >= 25)
	{
		sl_print_clbl_head(data);
		return ;
	}
	sl_print_clbl_nohead(data);
	return ;
}
