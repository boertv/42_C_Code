/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:29:18 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/17 16:24:06 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// parse arguments and shit innit
//char	**px_parser(char *argstr)
//{}

static pid_t	px_child_proc(t_fds *fds, char *cmd, char **args)
{
	if (dup2(fds->read, 0) == -1 || dup2(fds->pipe[1], 1) == -1)
	{
		px_free_all(cmd, args);
		px_abort("dup2", fds, 1);
	}
	if (close(fds->read) == -1)
	{
		px_free_all(cmd, args);
		fds->read = -1;
		px_abort("close", fds, 1);
	}
	if (px_close(fds->pipe) == -1)
	{
		px_free_all(cmd, args);
		px_abort("close", NULL, 1);
	}
	execve(cmd, args, NULL);
	px_free_all(cmd, args);
	px_abort("execve", fds, 1);
	return (1);
}

// runs cmd in fork, then calls free_all
// returns the pid of the child process
pid_t	px_cmd(t_fds *fds, char *cmd, char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		px_free_all(cmd, args);
		px_abort("fork", fds, 1);
	}
	if (pid == 0)
		return (px_child_proc(fds, cmd, args));
	else
	{
		px_free_all(cmd, args);
		return (pid);
	}
}
