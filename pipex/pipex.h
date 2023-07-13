/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:51:42 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/13 18:46:58 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/legacy/libft.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

void	px_open_pipe(int fd_read, int fd_pipe[2]);
void	px_cmd(int *fd_read, int fd_pipe[2], char *cmd, char **args);
void	px_reset_fds(int *fd_read, int fd_pipe[2]);

void	px_abort(const char *msg, int fdr, int fdp[2], int r);
int		px_close(int fd[2]);
void	px_free_all(char *str, char **arr);


//REMOVE ME PLSSSS
	#   include <stdio.h>
	//I AM BEGGING YOUUUUU

#endif
