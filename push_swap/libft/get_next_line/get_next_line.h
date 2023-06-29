/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:25:16 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/29 18:56:49 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE > 1000000
#   undef BUFFER_SIZE
#  endif
# endif

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 1
#   undef BUFFER_SIZE
#  endif
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_fdlist
{
	int				fd;
	char			buffer[BUFFER_SIZE + 1];
	struct s_fdlist	*next;
}	t_fdl;

char	*get_next_line(int fd);
ssize_t	ft_initialise(char **line, t_fdl **element, t_fdl **list, int fd);
ssize_t	ft_seek_nl(char *str);
char	*ft_null(char *line, t_fdl **list, int fd);

#endif
