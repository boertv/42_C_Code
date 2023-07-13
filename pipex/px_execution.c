/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:29:18 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/13 18:53:04 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// parse arguments and shit innit
// char	**px_parser(char *argstr)
// {}

static void	px_child_proc(int *fd_read, int fd_pipe[2], char *cmd, char **args)
{
printf("we in child PROCESS with fd_read = %i, fd_pipe[0] = %i\n", *fd_read, fd_pipe[0]);
	if (dup2(*fd_read, 0) == -1 || dup2(fd_pipe[0], 1) == -1)
	{
printf("we ABORTING after dup2\n");
		px_free_all(cmd, args);
		px_abort("dup2", *fd_read, fd_pipe, 1);
	}
printf("we commanding with fd_read = %i, fd_pipe[0] = %i\n", *fd_read, fd_pipe[0]);
	if (execve(cmd, args, NULL) == -1)
	{
printf("we ABORTING after execve\n");
		px_free_all(cmd, args);
		px_abort("execve", *fd_read, fd_pipe, 1);
	}
}

// runs cmd in fork, and wait till it's done.
// then free_all
void	px_cmd(int *fd_read, int fd_pipe[2], char *cmd, char **args)
{
	pid_t	pid;
	int		stat;

	pid = fork();
	if (pid == -1)
	{
		px_free_all(cmd, args);
		px_abort("fork", *fd_read, fd_pipe, 1);
	}
	if (pid == 0)
		px_child_proc(fd_read, fd_pipe, cmd, args);
	else
	{
		pid = waitpid(pid, &stat, 0);
printf("we in parent PROCESS with fd_read = %i, fd_pipe[0] = %i\n", *fd_read, fd_pipe[0]);
		// check for bad wait value with pid and stat
		px_free_all(cmd, args);
	}
}
