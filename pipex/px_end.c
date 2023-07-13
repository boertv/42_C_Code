/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:18:00 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/13 17:04:59 by bvercaem         ###   ########.fr       */
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

void	px_free_all(char *str, char **arr)
{
	if (str)
		free(str);
	if (arr)
		ft_clear_da(arr);
}

//perror(msg), closes fds, exit(r);
void	px_abort(const char *msg, int fdr, int fdp[2], int r)
{
	perror(msg);
	if (fdr > 2)
		if (close(fdr) == -1)
			perror("close");
	if (px_close(fdp) == -1)
		perror("close");
printf("we exiting\n");
	exit(r);
}
