/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:25:16 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/23 14:04:04 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE > 1000000
#   undef BUFFER_SIZE
#   define BUFFER_SIZE -1
#  endif
#  if BUFFER_SIZE < 1
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

char	*get_next_line(int fd);
ssize_t	ft_initialise(char **line, char **buffer);
ssize_t	ft_seek_nl(char *str);
char	*ft_null(char *line, char **buffer);

#endif
