/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_masks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:27:36 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/02 17:07:32 by bvercaem         ###   ########.fr       */
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

// exits if malloc failed
static void	sl_process_cr(t_sl_data *data, int x, int y)
{
	char	cr;

	cr = data->map[y][x];
	data->map[y][x] = EMPTY;
	data->mask_cr[y][x] = cr;
	if (!sl_add_cr(data, cr, x, y))
		return ;
	sl_flush_all(data);
	exit(1);
}

int	sl_create_mask_cr(t_sl_data *data)
{
	int	i;
	int	j;

	data->crs = malloc(sizeof(t_list *));
	if (!data->crs)
		return (1);
	*data->crs = NULL;
	data->mask_cr = sl_create_mask(data);
	if (!data->mask_cr)
	{
		free(data->crs);
		perror("mask malloc");
		return (1);
	}
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr(CR_CHARS, data->map[i][j]))
				sl_process_cr(data, j, i);
			j++;
		}
		i++;
	}
	return (0);
}
