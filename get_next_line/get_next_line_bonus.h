/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:25:16 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/15 17:39:34 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

					//AAAAAAAAAAAAAAAHH
							#include <stdio.h>

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 1
#   undef BUFFER_SIZE
#   define BUFFER_SIZE -1
#  endif
#  if BUFFER_SIZE > INT_MAX
#   undef BUFFER_SIZE
#   define BUFFER_SIZE -1
#  endif
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_fdlist
{
	int				fd;
	char			*buffer;
	struct s_fdlist	*next;
}	t_fdlist;

char	*get_next_line(int fd);
ssize_t	ft_initialise(char **line, t_fdlist **element, t_fdlist **list, int fd);
ssize_t	ft_seek_nl(char *str);
char	*ft_null(char *line, t_fdlist **list, t_fdlist **element);

#endif
