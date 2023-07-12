/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:29:28 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/12 17:17:28 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//puts read (dup2 old fd[1]) in fd[0] and new write in fd[1], closes old fd[0] if needed.
void	px_open_pipe(int fd[2])
{
	int	fd_new[2];
	int	bin;

	if (pipe(fd_new) == -1)
		px_abort(NULL, fd, 1);
	if (dup2(fd_new[0], fd[1]) == -1)
	{
		if (px_close(fd_new) == -1)
			perror(NULL);
		px_abort(NULL, fd, 1);
	}
	bin = fd[0];
	fd[0] = fd[1];
	fd[1] = fd_new[1];
	fd_new[1] = bin;
	if (px_close(fd_new) == -1)
		px_abort(NULL, fd, 1);
}
