/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:16:24 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/12 14:45:52 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_newbuf_freeline(char *buffer, char *line)
{
	char	*new;
	size_t	i;
	size_t	end;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	end = i;
	while (buffer[end])
		end++;
	new = malloc(BUFFER_SIZE + 1);
	if (!new)
		return (ft_null(NULL, &buffer));
	new[end - i] = 0;
	while (end-- > i)
		new[end - i] = buffer[end];
	free(line);
	free(buffer);
	return (new);
}

static void	ft_conform_input(ssize_t *i, char **buffer)
{
	if (*i == -1)
	{
		*i = 0;
		while ((*buffer)[*i])
			++*i;
	}
}

static char	*ft_append_res(char *line, char **buffer, ssize_t i)
{
	size_t	len;
	char	*res;

	ft_conform_input(&i, buffer);
	len = 0;
	while (line[len])
		len++;
	res = malloc(len + i + 1);
	if (!res)
		return (ft_null(line, buffer));
	res[len + i] = 0;
	while (i--)
		res[len + i] = (*buffer)[i];
	while (len--)
		res[len] = line[len];
	*buffer = ft_newbuf_freeline(*buffer, line);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	ssize_t		check;
	ssize_t		i;

	check = ft_initialise(&line, &buffer);
	if (!check)
		return (ft_null(line, &buffer));
	while (check > 0)
	{
		i = ft_seek_nl(buffer);
		if (i != -1)
			return (ft_append_res(line, &buffer, i));
		line = ft_append_res(line, &buffer, i);
		if (!line || !buffer)
			return (NULL);
		check = read(fd, buffer, BUFFER_SIZE);
		buffer[check] = 0;
	}
	return (ft_null(line, &buffer));
}
