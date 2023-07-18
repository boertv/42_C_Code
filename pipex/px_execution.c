/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:29:18 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/18 18:36:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	px_delete_qts(char **args, size_t i, char *cursor)
{
	char	qt;
	size_t	l;

	qt = *cursor;
	ft_strshift(cursor);
	l = cursor - args[i];
	while (!cursor && args[i + 1])
	{
		cursor = ft_strchr(args[i] + l, qt);
		if (!cursor)
		{
			l += ft_strlen(args[i] + l);
			px_da_join(args, i, " ");
		}
	}
	// possible cases:
	//	- i found a quote
	//	- i joined the last string (still need to search it)
	// that's it i think
}

static void	px_parser(char **args)
{
	size_t	i;
	char	*cursor;

	i = 0;
	while (!i || cursor) // euh i dunno yet
	{
		while (!cursor && args[i])
		{
			cursor = ft_strchrs(args[i], "\'\"");
			if (!cursor)
				i++;
		}
		if (!cursor)
			break ;
		px_delete_qts(args, i, cursor);
	}
	//when done maybe resize args to a smaller malloc?
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
	px_parser(args);
	// check cmd (args[0]) for quotes? and if path is already provided
	// check all of PATH (with char **env in main)?
	cmd = ft_strjoin("/bin/", args[0]);
	if (!cmd)
	{
		px_free_all(NULL, args);
		px_abort("strjoin", fds, 1);
	}
	// correct access check? (e.g. will just "/bin/" get through? (it will))
	if (access(cmd, X_OK) == -1)
	{
		px_free_all(cmd, args);
		px_abort("access failed", fds, 127);
	}
	return (px_forking(fds, cmd, args));
}
