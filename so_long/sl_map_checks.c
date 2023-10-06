/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:35:58 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/06 17:10:29 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_checks_init(t_sl_data *data, t_sl_map *checks)
{
	int	i;

	checks->err = 0;
	checks->exit = 0;
	checks->player = 0;
	data->clblt = 0;
	data->map_w = (int) ft_strlen(data->map[0]);
	i = 0;
	while (data->map[i])
		i++;
	data->map_h = i;
}

// returns -1 for a valid row, else returns the bad index.
static int	sl_row_check(char *row, int wall, t_sl_map *checks, t_sl_data *data)
{
	int	j;
	int	err;

	err = -1;
	if (row[0] != '1')
		err = 0;
	j = 0;
	while (row[j])
	{
		if (wall && row[j] != '1')
			err = j;
		if (row[j] == 'P')
			checks->player++;
		else if (row[j] == 'E')
			checks->exit++;
		else if (row[j] == 'C')
			data->clblt++;
		else if (!ft_strchr(MAP_CHARS, row[j]))
			sl_perr_map(MAP_ERR_CHAR, (row + j), checks);
		j++;
	}
	if (row[j - 1] != '1')
		err = j - 1;
	return (err);
}

static int	sl_map_final_checks(t_sl_data *data, t_sl_map *checks)
{
	if (checks->exit != 1)
		sl_perr_map(MAP_ERR_EXIT, NULL, checks);
	if (checks->player != 1)
		sl_perr_map(MAP_ERR_PLAYER, NULL, checks);
	if (data->clblt < 1)
		sl_perr_map(MAP_ERR_CLBLS, NULL, checks);
	return (sl_error_credits(checks));
}

// returns 1 for error, prints errors.
int	sl_map_check(t_sl_data *data)
{
	t_sl_map	checks;
	int			i;

	sl_checks_init(data, &checks);
	if (data->map_w < 3)
		return (sl_print_errmsg(&checks, "map: not wide enough", 1));
	if (data->map_h < 3)
		return (sl_print_errmsg(&checks, "map: not tall enough", 1));
	i = 0;
	while (data->map[i])
	{
		if ((int) ft_strlen(data->map[i]) != data->map_w)
			return (sl_perr_map(MAP_ERR_RECTLE, &i, &checks));
		if (sl_row_check(data->map[i], i == 0 || !data->map[i + 1],
				&checks, data) != -1)
			sl_perr_map(MAP_ERR_HOLE, &i, &checks);
		i++;
	}
	if (sl_map_final_checks(data, &checks))
		return (1);
	if (sl_map_solvable(data))
		return (1);
	return (0);
}
