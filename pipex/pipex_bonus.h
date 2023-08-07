/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:51:42 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/07 16:02:17 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"
# include "libft/get_next_line/get_next_line.h"

typedef struct s_heredoc
{
	int		is;
	char	*lim;
	size_t	limlen;
}			t_heredoc;

void	px_heredoc_check(char *s, int *i, t_fds *fds, t_heredoc *heredoc);
void	px_heredoc_pipe(t_fds *fds, char *lim, char **path, t_heredoc *heredoc);

#endif
