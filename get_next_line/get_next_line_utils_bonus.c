/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:33:19 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/15 17:43:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

ssize_t	ft_initialise(char **line, t_fdlist **element, t_fdlist **list, int fd)
{
printf("start ini: list = %p and *list = %p\n", list, *list);
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
printf("creating new element\n");
		*list = malloc (sizeof(t_fdlist));
		if (!*list)
			return (0);
		(*list)->fd = fd;
		(*list)->next = NULL;
		(*list)->buffer = NULL;
		*element = *list;
	}
printf("end ini: list = %p and *list = %p\n", list, *list);
	return (1);
}

// returns NULL. can clear a list or an element, element first
char	*ft_null(char *line, t_fdlist **list, t_fdlist **element)
{
	t_fdlist	*temp;
	t_fdlist	*tl;

	if (line)
		free(line);
	if (element && *element)
	{
		free((*element)->buffer);
		temp = *element;
		*element = (*element)->next;
		free(temp);
	}
	if (list && *list)
	{
		tl = *list;
		while (tl)
		{
			free(tl->buffer);
			temp = tl;
			tl = tl->next;
			free(temp);
		}
		*list = NULL;
	}
	return (NULL);
}
