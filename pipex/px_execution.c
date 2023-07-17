/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:29:18 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/17 18:46:19 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// parse arguments and shit innit
static void	px_parser(char **args)
{
	// |"h'i"1"2"3| is REALLY annoying
	// it's all one string but both the "" should be removed.
	size_t	i;
	char	*qte;
	size_t	j;

	i = 0;
	while (args[i])
	{
		qte = ft_strchr(args[i], '"');
		if (qte)
	}
}

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

static pid_t	px_forking(t_fds *fds, char *cmd, char **args)
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

// runs cmd in fork, then calls free_all
// returns the pid of the child process
pid_t	px_cmd(t_fds *fds, char *argv)
{
	pid_t	pid;
	char	*cmd;
	char	**args;

	args = ft_split(argv, ' ');
	if (!args)
		px_abort("split", fds, 1);
	// check cmd (args[0]) for quotes?
	cmd = ft_strjoin("/bin/", args[0]);
	if (!cmd)
	{
		px_free_all(NULL, args);
		px_abort("strjoin", fds, 1);
	}
	// correct access check? (e.g. will just "/bin/" get through?)
	if (access(cmd, X_OK) == -1)
	{
		px_free_all(cmd, args);
		px_abort("access failed", fds, 127);
	}
	px_parser(args);
	return (px_forking(fds, cmd, args));
}
