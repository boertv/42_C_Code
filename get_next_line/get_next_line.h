/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:25:16 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/12 13:18:29 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
		//AAAAAAAAAAAAAAAAAAAAAAAAAH
		#include <stdio.h>
		#include <unistd.h>
		//BBBBBBBBBBBBBBBBBBBBBBBBBH
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
ssize_t	ft_initialise(char **line, char **buffer);
ssize_t	ft_seek_nl(char *str);
char	*ft_null(char *line, char **buffer);

#endif
