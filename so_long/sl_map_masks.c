/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_masks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:27:36 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/25 16:10:56 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	sl_create_mask_cr(t_sl_data *data)
{
	int	i;
	int	j;

	data->mask_cr = sl_create_mask(data);
	if (!data->mask_cr)
	{
		perror("mask malloc");
		return (1);
	}
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == KNIGHT_R)
				data->mask_cr[i][j] = 'K';
			j++;
		}
		i++;
	}
	return (0);
}
