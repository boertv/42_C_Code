/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:29:28 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/13 16:56:14 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_open_pipe(int fd_read, int fd_pipe[2])
{
	if (pipe(fd_pipe) == -1)
		px_abort("pipe", fd_read, fd_pipe, 1);
}

// closes fd_read and fd_pipe[0] (sets to -1)
// moves fd_pipe[1] to fd_read
void	px_reset_fds(int *fd_read, int fd_pipe[2])
{
	int	temp;

	temp = fd_pipe[1];
	fd_pipe[1] = *fd_read;
	if (px_close(fd_pipe) == -1)
		px_abort("close", temp, NULL, 1);
	*fd_read = temp;
}
