/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:58:53 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/08 18:20:41 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char *av[], char **env)
{
	t_fds		fds;
	int			i;
	char		**path;
	t_heredoc	heredoc;

	px_heredoc_check(av[1], &i, &fds, &heredoc);
	px_heredoc_pipe(&fds, av[2], NULL, &heredoc);
	path = px_infd_extract_path(&fds, av[1], env, heredoc.is);
	while (i < ac - 2)
	{
		px_open_pipe(&fds, path);
		px_cmd(&fds, av[i], path);
		px_reset_fds(&fds);
		i++;
	}
	if (heredoc.is)
		fds.pipe[1] = 0;
	i = px_final_process(av[ac - 2], av[ac - 1], &fds, path);
	px_flush(&fds, path);
	return (i);
}
