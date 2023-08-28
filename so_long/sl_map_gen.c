/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:13:01 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/28 17:53:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_file_check(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	if (i < 5)
		return (1);
	if (ft_strncmp(file + (i - 4), ".ber", 4))
		return (1);
	return (0);
}

// returns NULL if open fails.
char	**sl_create_map(char *file)
{
	int		fd;
	char	**map;
	int		i;
	char	*string;

	i = 0;
	fd = open(file, O_RDONLY);
	string = get_next_line(fd);
	while (string)
	{
		i++;
		free(string);
		string = get_next_line(fd);
	}
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
	{
		string = ft_strrchr(map[i], '\n');
		if (string)
			*string = 0;
	}
	return (map);
}

// returns -1 for a valid row, else returns the bad index.
int	sl_map_row_check(char *row, int wall, t_sl_map *checks, t_sl_data *data)
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
		else if (row[j] == 'E')
			checks->exit++;
		else if (row[j] == 'C')
			data->clbls++;
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
	if (data->clbls < 1)
		sl_perr_map(MAP_ERR_CLBLS, NULL, checks);
	if (checks->err)
	{
		if (checks->err > 10)
		{
			ft_printf("%fd...\n", 2);
			ft_printf("%fdso_long printed 10/%i errors\n", 2, checks->err);
		}
		else if (checks->err > 1)
			ft_printf("%fdso_long printed %i errors\n", 2, checks->err);
		return (1);
	}
	return (0);
}

// returns 1 for error, prints errors.
int	sl_map_check(t_sl_data *data)
{
	t_sl_map	checks;
	int			i;

	checks.err = 0;
	checks.exit = 0;
	checks.player = 0;
	data->clbls = 0;
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
			sl_perr_map(MAP_ERR_HOLE, &i, &checks);
		i++;
	}
	if (sl_map_final_checks(data, &checks))
		return (1);
// add solvable check in here!
	return (0);
}
