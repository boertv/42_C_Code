/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:29:28 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/14 18:01:59 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_open_pipe(t_fds *fds)
{
	if (pipe(fds->pipe) == -1)
		px_abort("pipe", fds, 1);
}

// closes read and pipe[1] (sets to -1)
// moves pipe[0] to read
void	px_reset_fds(t_fds *fds)
{
	int	temp;

	temp = fds->pipe[0];
	fds->pipe[0] = fds->read;
	if (px_close(fds->pipe) == -1)
	{
		fds->pipe[0] = -1;
		fds->pipe[1] = -1;
		px_abort("close", fds, 1);
	}
	fds->read = temp;
}
