/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:18:00 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/22 14:00:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//returns -1 if a 'close' fails
int	px_close(int fd[2])
{
	int	err;

	err = 0;
	if (fd)
	{
		if (fd[0] > 2)
		{
			if (close(fd[0]) == -1)
				err = -1;
			fd[0] = -1;
		}
		if (fd[1] > 2)
		{
			if (close(fd[1]) == -1)
				err = -1;
			fd[1] = -1;
		}
	}
	return (err);
}

// frees if not NULL, returns r.
int	px_free_all(char *str, char **arr, int r)
{
	if (str)
		free(str);
	if (arr)
		ft_clear_da(arr);
	return (r);
}

void	px_free_and_abort(const char *msg, t_fds *fds, t_args *args, int r)
{
	if (ft_strncmp(msg, "DNP", 4))
	{
		write (STDERR_FILENO, "pipex: ", 7);
		perror(msg);
	}
	if (args)
		px_free_all(args->cmd, args->arg, 0);
	px_abort("DNP", fds, args->path, r);
}

//perror(msg), clear path, close fds, wait out all children, exit(r);
void	px_abort(const char *msg, t_fds *fds, char **path, int r)
{
	if (ft_strncmp(msg, "DNP", 4))
	{
		write (STDERR_FILENO, "pipex: ", 7);
		perror(msg);
	}
	ft_clear_da(path);
	if (fds)
	{
		if (fds->read > 2)
			if (close(fds->read) == -1)
				perror("close");
		fds->read = -1;
		if (px_close(fds->pipe) == -1)
			perror("close");
	}
	while (wait(NULL) != -1)
		continue ;
	exit(r);
}

// perror(msg), clear args, return (r). (msg "DNP" doesn't call perror)
int	px_free_perror(const char *msg, t_args *args, int r)
{
	if (ft_strncmp(msg, "DNP", 4))
	{
		write(STDERR_FILENO, "pipex: ", 7);
		perror(msg);
	}
	if (args)
		px_free_all(args->cmd, args->arg, 0);
	return (r);
}
