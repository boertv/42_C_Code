/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_animations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:29:25 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/27 17:50:28 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_clear_animation(t_sl_data *data, t_animation *am)
{
	int	i;

	i = 0;
	while (am->imgs[i])
	{
		mlx_destroy_image(data->mlx, am->imgs[i]);
		i++;
	}
	free(am->imgs);
}

int	sl_load_animations(t_sl_data *data)
{
	data->am = malloc (sizeof(t_amlib));
}
