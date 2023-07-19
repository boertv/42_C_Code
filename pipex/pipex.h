/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:51:42 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/19 18:19:22 by bvercaem         ###   ########.fr       */
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

void	px_open_pipe(t_fds *fds);
pid_t	px_cmd(t_fds *fds, char *argv);
void	px_reset_fds(t_fds *fds);
int		px_da_join(char **da, size_t i, const char *c);

void	px_abort(const char *msg, t_fds *fds, int r);
int		px_close(int fd[2]);
void	px_free_all(char *str, char **arr);

#endif
