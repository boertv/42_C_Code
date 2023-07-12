/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:18:00 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/12 17:16:19 by bvercaem         ###   ########.fr       */
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
			fd[0] == -1;
		}
		if (fd[1] > 2)
		{
			if (close(fd[1]) == -1)
				err = -1;
			fd[1] == -1;
		}
	}
	return (err);
}

//perror(msg), closes fd, exit(r);
void	px_abort(const char *msg, int fd[2], int r)
{
	perror(msg);
	if (px_close(fd) == -1)
		perror(NULL);
	exit(r);
}
