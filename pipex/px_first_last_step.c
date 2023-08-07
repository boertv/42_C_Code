/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_first_last_step.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:23:26 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/07 17:58:21 by bvercaem         ###   ########.fr       */
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

// if fds->pipe[1] == 0 we append instead of tuncating.
int	px_final_process(char *cmd, char *out, t_fds *fds, char **path)
{
	pid_t	pid;
	int		stat;

	if (!fds->pipe[1])
		fds->pipe[1] = open(out, O_WRONLY | O_APPEND | O_CREAT, 00755);
	else
		fds->pipe[1] = open(out, O_WRONLY | O_TRUNC | O_CREAT, 00755);
	if (fds->pipe[1] == -1)
		px_abort(out, fds, path, 1);
	pid = px_cmd(fds, cmd, path);
	pid = waitpid(pid, &stat, 0);
	if (pid == -1 || !WIFEXITED(stat))
		perror (cmd);
	return (WEXITSTATUS(stat));
}

static int	px_append_da(char **da, char *app)
{
	size_t	i;

	i = 0;
	while (da[i])
	{
		if (px_da_join_const(da, i, app))
			return (1);
		i++;
	}
	return (0);
}

// opens infile, finds PATH variable in env and returns the split path.
char	**px_infd_extract_path(t_fds *fds, char *file, char **env, int hdbool)
{
	size_t	i;
	char	**path;

	if (!hdbool)
		fds->read = open(file, O_RDONLY);
	if (fds->read == -1)
		perror(file);
	i = 0;
	path = NULL;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (env[i])
		path = ft_split(env[i] + 5, ':');
	if (!path)
		px_abort("environment parsing", fds, NULL, 1);
	if (px_append_da(path, "/"))
		px_abort("px_da_join_const", fds, path, 1);
	return (path);
}
