/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:29:18 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/09 20:09:56 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// returns NULL if a quote is not closed
static char	*px_delete_qts(char **args, size_t i, char *cursor)
{
	char	qt;
	size_t	l;

	qt = *cursor;
	ft_strshift(cursor);
	l = cursor - args[i];
	cursor = ft_strchr(args[i] + l, qt);
	while (!cursor && args[i + 1])
	{
		l += ft_strlen(args[i] + l);
		px_da_join(args, i, " ");
		cursor = ft_strchr(args[i] + l, qt);
	}
	if (cursor)
		ft_strshift(cursor);
	return (cursor);
}

// returns 1 if a quote is not closed or resize malloc failed
static int	px_parser(t_args *args)
{
	size_t	i;
	char	*cursor;

	i = 0;
	while (args->arg[i])
	{
		cursor = ft_strchrs(args->arg[i], "\'\"");
		while (!cursor && args->arg[i])
		{
			i++;
			cursor = ft_strchrs(args->arg[i], "\'\"");
		}
		if (!cursor)
			break ;
		while (cursor)
		{
			cursor = px_delete_qts(args->arg, i, cursor);
			if (!cursor)
				return (1);
			cursor = ft_strchrs(cursor, "\'\"");
		}
		i++;
	}
	args->arg = px_resize_malloc(args->arg);
	return (!args->arg);
}

static pid_t	px_child_proc(t_fds *fds, t_args *args)
{
	if (access(args->cmd, X_OK) == -1)
		px_free_and_abort("DNP", fds, args, 127);
	if (dup2(fds->read, 0) == -1 || dup2(fds->pipe[1], 1) == -1)
		return (px_free_perror("dup2", args, 1));
	if (close(fds->read) == -1)
	{
		fds->read = -1;
		px_free_and_abort("close", fds, args, 1);
	}
	if (px_close(fds->pipe) == -1)
		px_free_and_abort("close", NULL, args, 1);
	execve(args->cmd, args->arg, NULL);
	px_free_and_abort("execve", fds, args, 126);
	exit(126);
}

static pid_t	px_forking(t_fds *fds, t_args *args)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (px_free_perror("fork", args, -1));
	if (pid == 0)
		return (px_child_proc(fds, args));
	else
	{
		px_free_all(args->cmd, args->arg, 0);
		return (pid);
	}
}

// runs cmd in fork, then calls free_all
// returns the pid of the child process
pid_t	px_cmd(t_fds *fds, char *argv, char **path)
{
	t_args	args;

	if (fds->read == -1)
	{
		if (close(fds->pipe[1]))
			px_abort("close", fds, path, 1);
		fds->pipe[1] = -1;
		return (-1);
	}
	args.path = path;
	args.arg = ft_split(argv, ' ');
	if (!args.arg)
		return (px_free_perror("split", NULL, 1));
	args.cmd = NULL;
	if (px_parser(&args))
		return (px_free_perror("parsing", &args, 1));
	if (access(args.arg[0], X_OK) == -1)
		args.cmd = px_path_parser(args.arg[0], path);
	else
		args.cmd = ft_strdup(args.arg[0]);
	if (!args.cmd)
		return (px_free_perror("strjoin", &args, 1));
	return (px_forking(fds, &args));
}
