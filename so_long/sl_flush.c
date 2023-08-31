/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_flush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:23:48 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/31 14:21:03 by bvercaem         ###   ########.fr       */
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

void	sl_flush_loop(t_sl_data *data)
{
	sl_flush_all(data);
	mlx_destroy_window(data->mlx, data->win);
}
