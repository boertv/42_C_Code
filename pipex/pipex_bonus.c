/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:58:53 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/25 16:23:53 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char *av[])
{
	t_fds	fds;
	int		i;
	pid_t	pid;
	int		stat;

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
	fds.pipe[1] = open(av[ac - 1], O_WRONLY);
	if (fds.pipe[1] == -1)
		px_abort(av[ac - 1], &fds, 1);
	pid = px_cmd(&fds, av[ac - 2]);
	pid = waitpid(pid, &stat, 0);
	// check for bad wait value with pid and stat
	// wait for all proccesses with a wait loop (if no more PID's it returns -1)
	fds.pipe[0] = fds.read;
	if (px_close(fds.pipe) == -1)
		px_abort("close", NULL, 1);
}
