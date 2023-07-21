/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:51:14 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/21 17:56:27 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// static int	px_final_step()
// {
// }

int	main(int ac, char *av[])
{
	t_fds	fds;
	int		i;
	pid_t	pid;
	int		stat;

	// seperate mandotory main that checks if ac == 4.
	// check all of PATH (with char **env in main)?
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
	fds.pipe[0] = fds.read;
	if (px_close(fds.pipe) == -1)
		px_abort("close", NULL, 1);
}
