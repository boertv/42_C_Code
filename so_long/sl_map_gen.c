/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:13:01 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/29 15:48:34 by bvercaem         ###   ########.fr       */
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

static char	**sl_first_malloc(char *file)
{
	int		i;
	int		fd;
	char	*string;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		return (NULL);
	}
	string = get_next_line(fd);
	while (string)
	{
		i++;
		free(string);
		string = get_next_line(fd);
	}
	close(fd);
	map = malloc((i + 1) * sizeof(char *));
	if (!map)
		perror("map malloc: ");
	return (map);
}

static void	sl_rm_nl(char **map, int i)
{
	char	*string;

	while (i--)
	{
		string = ft_strrchr(map[i], '\n');
		if (string)
			*string = 0;
	}
}

// returns NULL if open fails.
char	**sl_create_map(char *file)
{
	int		fd;
	char	**map;
	int		i;

	map = sl_first_malloc(file);
	if (!map)
		return (NULL);
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
	sl_rm_nl(map, i);
	return (map);
}
