/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:13:01 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/24 14:16:55 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns NULL if open fails.
char	**sl_create_map(char *file)
{
	int		fd;
	char	**map;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd))
		i++;
	map = malloc((i + 1) * sizeof(char *));
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	close(fd);
	while (i--)
		if (ft_strrchr(map[i], '\n'))
			*ft_strrchr(map[i], '\n') = 0;
	return (map);
}

// returns -1 for a valid row, else returns the bad index.
int	sl_map_row_check(char *row, int wall, t_map *checks, t_game_data *data)
{
	int	j;
	int	err;

	err = -1;
	if (row[0] != '1')
		err = 0;
	j = 1;
	while (row[j])
	{
		if (wall && row[j] != '1')
			err = j;
		if (row[j] == 'P')
			checks->player++;
		if (row[j] == 'E')
			checks->exit++;
		if (row[j] == 'C')
			data->collbs++;
		j++;
	}
	if (row[j - 1] != '1')
		err = j - 1;
	return (err);
}

// returns 1 for error, prints errors.
int	sl_map_check(t_game_data *data)
{
	t_map	checks;
	int		i;

	checks.err = 0;
	checks.exit = 0;
	checks.player = 0;
	data->collbs = 0;
	checks.width = ft_strlen(data->map[0]);
	if (checks.width < 3)
		return (sl_print_msg("map: not wide enough", 1));
	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != checks.width)
			return (sl_print_msg("map: not a rectangle", 1));
		if (sl_map_row_check(data->map[i], i == 0 || !data->map[i + 1],
				&checks, data) != -1)
		{
			ft_printf("%fdso_long: map: hole in the wall (row %i)\n", 2, i + 1);
			checks.err++;
		}
		i++;
	}
	if (checks.exit != 1)
		checks.err += sl_print_msg("map: not exactly one exit", 1);
	if (checks.player != 1)
		checks.err += sl_print_msg("map: not exactly one player", 1);
	if (checks.err)
	{
		ft_printf("%fdso_long: printed %i errors\n", 2, checks.err);
		return (1);
	}
	return (0);
}
