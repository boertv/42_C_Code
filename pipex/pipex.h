/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:51:42 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/07 15:25:27 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/legacy/libft.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_fds
{
	int	read;
	int	pipe[2];
}		t_fds;

typedef struct s_args
{
	char	*cmd;
	char	**arg;
	char	**path;
}			t_args;

char	**px_open_in_extract_path(t_fds *fds, char *file, char **env, int herebool);
int		px_final_process(char *cmd, char *out, t_fds *fds, char **path);

void	px_open_pipe(t_fds *fds, char **path);
pid_t	px_cmd(t_fds *fds, char *argv, char **path);
char	*px_path_parser(char *cmd, char **path);
void	px_reset_fds(t_fds *fds, char **path);
int		px_da_join(char **da, size_t i, const char *c);
int		px_da_join_const(char **da, size_t i, const char *c);
char	**px_resize_malloc(char	**da);

void	px_abort(const char *msg, t_fds *fds, char **path, int r);
void	px_free_and_abort(const char *msg, t_fds *fds, t_args *args, int r);
int		px_close(int fd[2]);
int		px_free_all(char *str, char **arr, int r);
void	px_flush(t_fds *fds, char **path);

#endif
