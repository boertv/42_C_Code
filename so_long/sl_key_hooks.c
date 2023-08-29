/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:00:49 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/29 17:05:37 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_key_hook_hub(int key, t_sl_data *data)
{
	(void)key;
	sl_flush_all(data);
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}
