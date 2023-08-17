/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:33:19 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/29 18:57:59 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// returns -1 if no \n found, else returns index of \n
ssize_t	ft_seek_nl(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (++i);
	return (-1);
}

static int	ft_add_el(t_fdl **list, int fd)
{
	*list = malloc (sizeof(t_fdl));
	if (!*list)
		return (0);
	(*list)->fd = fd;
	(*list)->next = NULL;
	(*list)->buffer[0] = 0;
	return (1);
}

// returns 0 on error, else returns 1
ssize_t	ft_initialise(char **line, t_fdl **element, t_fdl **list, int fd)
{
	*line = malloc(2);
	if (!*line)
		return (0);
	**line = 0;
	while (list && *list)
	{
		if ((*list)->fd == fd)
		{
			*element = *list;
			break ;
		}
		list = &((*list)->next);
	}
	if (list && !*list)
	{
		if (!ft_add_el(list, fd))
			return (0);
		*element = *list;
	}
	return (1);
}

static void	ft_clear_list(t_fdl **list)
{
	t_fdl	*temp;
	t_fdl	*tl;

	tl = *list;
	while (tl)
	{
		temp = tl;
		tl = tl->next;
		free(temp);
	}
	*list = NULL;
}

// returns NULL. can clear a list if fd == -1;
char	*ft_null(char *line, t_fdl **list, int fd)
{
	t_fdl	*temp;

	if (line)
		free(line);
	if (fd > -1 && list)
	{
		while (*list && (*list)->fd != fd)
			list = &((*list)->next);
		if (!*list)
			return (NULL);
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
	if (fd == -1 && list)
		ft_clear_list(list);
	return (NULL);
}
