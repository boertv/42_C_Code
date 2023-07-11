/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:07:33 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/11 18:12:53 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//returns -1 if an 'open' or 'dup2' failed.
//always closes all non-std fds
int	px_set_files(t_fds *fds, char *infile, char *outfile)
{
	fds->inf = open(infile, O_RDONLY);
	if (fds->inf == -1)
		return (-1);
	fds->outf = open(outfile, O_WRONLY);
	if (fds->outf == -1)
	{
		close(fds->inf);
		return (-1);
	}
	if (dup2(fds->inf, 0) == -1 || dup2(fds->outf, 1) == -1)
	{
		close(fds->inf);
		close(fds->outf);
		return (-1);
	}
	close(fds->inf);
	close(fds->outf);
	fds->inf = STDIN_FILENO;
	fds->outf = STDOUT_FILENO;
	return (0);
}
