/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:58:53 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/25 18:31:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	px_final_process(char *cmd, char *out, t_fds *fds)
{
	pid_t	pid;
	int		stat;

	fds->pipe[1] = open(out, O_WRONLY);
	if (fds->pipe[1] == -1)
		px_abort(out, fds, 1);
	pid = px_cmd(fds, cmd);
	pid = waitpid(pid, &stat, 0);
	// check for bad wait value with pid and stat
}

int	main(int ac, char *av[])
{
	t_fds	fds;
	int		i;

	// check all of PATH (with char **env in main)?
	// open file for HERE_DOC bonus in append mode
	i = 2;
	fds.read = open(av[1], O_RDONLY);
	if (fds.read == -1)
		px_abort(av[1], NULL, 1);
	while (i < ac - 2)
	{
		px_open_pipe(&fds);
		px_cmd(&fds, av[i]);
		px_reset_fds(&fds);
		i++;
	}
	px_final_process(av[ac - 2], av[ac - 1], &fds);
	// wait for all processes with a wait loop (if no more PID's it returns -1)
	fds.pipe[0] = fds.read;
	if (px_close(fds.pipe) == -1)
		px_abort("close", NULL, 1);
}
