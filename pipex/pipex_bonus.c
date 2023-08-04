/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:58:53 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/04 15:05:07 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char *av[], char **env)
{
	t_fds	fds;
	int		i;
	char	**path;
	int		herebool;

	// read stdin for here_doc with limiter (with temp file flag for 'open'?)
	px_heredoc_check(av[1], &i, &fds, &herebool);
	path = px_open_in_extract_path(&fds, av[1], env);
	while (i < ac - 2)
	{
		px_open_pipe(&fds, path);
		px_cmd(&fds, av[i], path);
		px_reset_fds(&fds, path);
		i++;
	}
	if (herebool)
		fds.pipe[1] = 0;
	i = px_final_process(av[ac - 2], av[ac - 1], &fds, path);
	px_flush(&fds, path);
	return (i);
}
