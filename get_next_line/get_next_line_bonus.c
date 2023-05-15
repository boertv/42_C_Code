/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:16:24 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/15 18:10:42 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_newbuf_freeline(t_fdlist *element, char *line)
{
	char	*new;
	size_t	i;
	size_t	end;

	free(line);
	i = 0;
	while (element->buffer[i] && element->buffer[i] != '\n')
		i++;
	if (element->buffer[i] == '\n')
		i++;
	end = i;
	while (element->buffer[end])
		end++;
	new = malloc(BUFFER_SIZE + 1);
	if (!new)
		return (ft_null(NULL, NULL, &element));
	new[end - i] = 0;
	while (end-- > i)
		new[end - i] = element->buffer[end];
	free(element->buffer);
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

static char	*ft_append_res(char *line, t_fdlist *element, ssize_t i)
{
	size_t	len;
	char	*res;

	ft_conform_input(&i, &(element->buffer));
	len = 0;
	while (line[len])
		len++;
	res = malloc(len + i + 1);
	if (!res)
		return (ft_null(line, NULL, &element));
	res[len + i] = 0;
	while (i--)
		res[len + i] = (element->buffer)[i];
	while (len--)
		res[len] = line[len];
	element->buffer = ft_newbuf_freeline(element, line);
	return (res);
}

static char	*ft_exit(char *line, t_fdlist *el, ssize_t check)
{
	if (check == -1 || (line && !*line))
		return (ft_null(line, NULL, &el));
	return (line);
}

char	*get_next_line(int fd)
{
	static t_fdlist	*list = NULL;
	t_fdlist		*element;
	char			*line;
	ssize_t			check;
	ssize_t			i;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	check = ft_initialise(&line, &element, &list, fd);
	if (!check)
		return (ft_null(line, NULL, &element));
printf("element = %p\n", element);
printf("buffer = %s\n", element->buffer);
printf("\\(^.^)/ \\(^.^)/ \\(^.^)/\n");
	while (check > 0)
	{
		i = ft_seek_nl(element->buffer);
		if (i != -1)
			return (ft_append_res(line, element, i));
printf("seeked\n");
		line = ft_append_res(line, element, i);
		if (!line || !(element->buffer))
			return (ft_null(line, NULL, &element));
printf("lined\n");
		check = read(fd, element->buffer, BUFFER_SIZE);
		if (check >= 0)
			(element->buffer)[check] = 0;
printf("checked\n");
	}
printf("finishing up\n");
	return (ft_exit(line, element, check));
}
