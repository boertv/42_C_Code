/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:51:14 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/04 14:53:47 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char **env)
{
	// check error handling, compare with bash cmd
	t_fds	fds;
	int		i;
	char	**path;

	if (ac != 5)
		return (1);
	fds.read = -1;
	path = px_open_in_extract_path(&fds, av[1], env);
	i = 2;
	while (i < ac - 2)
	{
		px_open_pipe(&fds, path);
		px_cmd(&fds, av[i], path);
		px_reset_fds(&fds, path);
		i++;
	}
	i = px_final_process(av[ac - 2], av[ac - 1], &fds, path);
	px_flush(&fds, path);
	return (i);
}
