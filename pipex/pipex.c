/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:51:14 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/25 18:43:33 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	// return according to pid
}

int	main(int ac, char *av[])
{
	t_fds	fds;
	int		i;

	// check all of PATH (with char **env in main)?
	if (ac != 5)
		return (1);
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
	i = px_final_process(av[ac - 2], av[ac - 1], &fds);
	while (wait(NULL) != -1)
		continue ;
	fds.pipe[0] = fds.read;
	if (px_close(fds.pipe) == -1)
		px_abort("close", NULL, 1);
	return (i);
}
