/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:51:14 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/12 17:22:50 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[])
{
	int	fd[2];
	int	i;

	i = 2;
	//CHECK: make fd with infile to use in first pipe
	fd[1] = open(av[1], O_RDONLY);
	if (fd[1] == -1)
		px_abort(av[1], NULL, 1);
	while (i < ac - 2)
	{
		//CHECK: open pipe, dup read = last write, write = new fd 	//shuffle so fd[n] is all good
		px_open_pipe(fd);
		//parse argument and run cmd with fork (and wait till done?)
		//CHECK in px_open_pipe: close last write/current read 	//N/A: set to -1 for ease of use
		i++;
	}
	//close last fd[0]
	//do the last cmd with in = out of last pipe and out = outfile
	//close all thingies?
}
