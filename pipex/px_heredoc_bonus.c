/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:44:55 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/22 15:39:23 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	px_heredoc_check(char *s, int *i, t_fds *fds, t_heredoc *heredoc)
{
	fds->read = -1;
	fds->pipe[0] = -1;
	fds->pipe[1] = -1;
	if (!ft_strncmp(s, "here_doc", 9))
	{
		*i = 3;
		heredoc->is = 1;
		return ;
	}
	*i = 2;
	heredoc->is = 0;
	return ;
}

static int	px_heredoc_read(int fd, t_heredoc *heredoc)
{
	char	*input;

	if (write (1, "> ", 2) == -1)
		return (1);
	input = get_next_line(0);
	while (input)
	{
		if (ft_strlen(input) == heredoc->limlen + 1
			&& !ft_strncmp(input, heredoc->lim, heredoc->limlen))
			return (px_free_all(input, NULL, 0));
		if (write(fd, input, ft_strlen(input)) == -1)
			return (px_free_all(input, NULL, 1));
		if (input)
			free(input);
		if (write (1, "> ", 2) == -1)
			return (1);
		input = get_next_line(0);
	}
	return (0);
}

void	px_heredoc_pipe(t_fds *fds, char *lim, char **path, t_heredoc *heredoc)
{
	int	check;

	if (!heredoc->is)
		return ;
	heredoc->lim = lim;
	heredoc->limlen = ft_strlen(lim);
	px_open_pipe(fds, path);
	fds->read = fds->pipe[0];
	fds->pipe[0] = -1;
	check = px_heredoc_read(fds->pipe[1], heredoc);
	get_next_line(-1);
	if(check)
		px_abort("write", fds, path, 1);
	close(fds->pipe[1]);
	fds->pipe[1] = -1;
}
