/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:51:14 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/13 18:46:54 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[])
{
	int	fd_read;
	int	fd_pipe[2];
	int	i;
	//temp char pointers
	char	*cmd = ft_strdup("/bin/cat");
	char	**args = NULL;

	i = 2;
	fd_read = open(av[1], O_RDONLY);
	if (fd_read == -1)
		px_abort(av[1], 0, NULL, 1);
	while (i < ac - 2)
	{
		px_open_pipe(fd_read, fd_pipe);
		px_cmd(&fd_read, fd_pipe, cmd, args);
		cmd = ft_strdup("/bin/cat");
		px_reset_fds(&fd_read, fd_pipe);
		i++;
	}
	//do the last cmd with in = out of last pipe and out = outfile
	fd_pipe[0] = open(av[ac - 1], O_WRONLY);
	if (fd_pipe[0] == -1)
	{
		px_free_all(cmd, args);
		px_abort(av[ac - 1], fd_read, NULL, 1);
	}
	px_cmd(&fd_read, fd_pipe, cmd, args);
	//close fd_read and outfile?
	fd_pipe[1] = fd_read;
	if (px_close(fd_pipe) == -1)
		px_abort("close", 0, NULL, 1);
}

/*
WHILE LOOP:
	+- open pipe with fd_pipe
	-- run (parsed) cmd (fork) with in = fd_read, out = fd_pipe[0]
	+- wait for child process
	+- close fd_read and fd_pipe[0] (set to -1)
	+- move fd_pipe[1] to fd_read
*/
