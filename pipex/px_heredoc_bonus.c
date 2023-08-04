/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:44:55 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/04 14:48:24 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	px_heredoc_check(char *s, int *i, t_fds *fds, int *herebool)
{
	if (!ft_strncmp(s, "here_doc", 9))
	{
		*i = 3;
		fds->read = 0;
		*herebool = 1;
		return ;
	}
	*i = 2;
	fds->read = -1;
	*herebool = 0;
	return ;
}
