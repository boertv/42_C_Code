/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:58:53 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/02 18:13:46 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char *av[], char **env)
{
	t_fds	fds;
	int		i;
	char	**path;

	// open file for HERE_DOC bonus in append mode
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
