/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_first_last_step.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:23:26 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/02 18:03:35 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// wait on all children, close fds.read and fds.pipe[1], clear path
void	px_flush(t_fds *fds, char **path)
{
	while (wait(NULL) != -1)
		continue ;
	fds->pipe[0] = fds->read;
	if (px_close(fds->pipe) == -1)
		px_abort("close", NULL, path, 1);
	ft_clear_da(path);
}

int	px_final_process(char *cmd, char *out, t_fds *fds, char **path)
{
	pid_t	pid;
	int		stat;

	fds->pipe[1] = open(out, O_WRONLY);
	if (fds->pipe[1] == -1)
		px_abort(out, fds, path, 1);
	pid = px_cmd(fds, cmd, path);
	pid = waitpid(pid, &stat, 0);
	// check for bad wait value with pid and stat
	// return according to pid
	return (0);
}

// opens infile, finds PATH variable in env and returns the split path.
char	**px_open_in_extract_path(t_fds *fds, char *file, char **env)
{
	size_t	i;
	char	**path;

	fds->read = open(file, O_RDONLY);
	if (fds->read == -1)
		px_abort(file, NULL, NULL, 1);
	i = 0;
	path = NULL;
	while (env[i] && ft_strncmp(env[i], "PATH", 4))
		i++;
	if (env[i])
		path = ft_split(env[i], ':');
	if (!path)
	{
		close (fds->read);
		px_abort("environment parsing", NULL, NULL, 1);
	}
	i = 0;
	while (path[i])
	{
		if (px_da_join_const(path, i, "/"))
		{
			close (fds->read);
			px_abort("px_da_join_const", NULL, path, 1);
		}
		i++;
	}
	return (path);
}
