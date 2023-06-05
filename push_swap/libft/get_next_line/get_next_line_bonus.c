/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:16:24 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/23 14:35:13 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_newbuf(t_fdl **element)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((*element)->buffer[i] && (*element)->buffer[i] != '\n')
		i++;
	j = i + 1;
	while ((*element)->buffer[i++])
		(*element)->buffer[i - j] = (*element)->buffer[i];
}

static void	ft_conform_input(ssize_t *i, char *buffer)
{
	if (*i == -1 && buffer)
	{
		*i = 0;
		while (buffer[*i])
			++*i;
	}
}

static char	*ft_append_res(char *line, t_fdl **el, t_fdl **list, ssize_t i)
{
	size_t	len;
	char	*res;

	ft_conform_input(&i, ((*el)->buffer));
	len = 0;
	while (line[len])
		len++;
	res = malloc(len + i + 1);
	if (!res)
		return (ft_null(line, list, (*el)->fd));
	res[len + i] = 0;
	while (i--)
		res[len + i] = (*el)->buffer[i];
	while (len--)
		res[len] = line[len];
	free(line);
	ft_newbuf(el);
	return (res);
}

static char	*ft_exit(char *line, t_fdl **list, ssize_t check, int fd)
{
	if (check == -1 || (line && !*line))
		return (ft_null(line, list, fd));
	return (line);
}

char	*get_next_line(int fd)
{
	static t_fdl	*list = NULL;
	t_fdl			*element;
	char			*line;
	ssize_t			check;
	ssize_t			i;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	check = ft_initialise(&line, &element, &list, fd);
	if (!check)
		return (ft_null(line, &list, fd));
	while (check > 0)
	{
		i = ft_seek_nl(element->buffer);
		if (i != -1)
			return (ft_append_res(line, &element, &list, i));
		line = ft_append_res(line, &element, &list, i);
		if (!line)
			return (ft_null(line, &list, fd));
		check = read(fd, element->buffer, BUFFER_SIZE);
		if (check >= 0)
			(element->buffer)[check] = 0;
	}
	return (ft_exit(line, &list, check, fd));
}
