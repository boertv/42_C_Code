/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:33:19 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/11 17:50:02 by bvercaem         ###   ########.fr       */
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

char	*ft_null(char *line, char **buffer)
{
	if (line)
		free(line);
	if (*buffer)
		free(*buffer);
	*buffer = NULL;
	return (NULL);
}
