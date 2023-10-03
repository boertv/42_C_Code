/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:18:13 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/03 16:47:56 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// doesn't free anything mind you.
int	sl_print_errno(char *msg, int rtrn)
{
	perror(msg);
	return (rtrn);
}

int	sl_print_errmsg(t_sl_map *checks, char *msg, int rtrn)
{
	if (checks)
	{
		checks->err++;
		if (checks->err == 1)
			write (STDERR_FILENO, "Error\n", 6);
	}
	else
		write (STDERR_FILENO, "Error\n", 6);
	write (STDERR_FILENO, msg, ft_strlen(msg));
	write (STDERR_FILENO, "\n", 1);
	return (rtrn);
}

int	sl_error_credits(t_sl_map *checks)
{
	if (checks->err)
	{
		if (checks->err > 10)
		{
			ft_printf("%fd...\n", 2);
			ft_printf("%fdso_long printed 10 of %i errors\n", 2, checks->err);
		}
		else if (checks->err > 3)
			ft_printf("%fdso_long printed %i errors\n", 2, checks->err);
		return (1);
	}
	return (0);
}

static int	sl_perr_map_2(int err, void *p, t_sl_map *checks)
{
	if (err == MAP_ERR_PLAYER)
	{
		if (!checks->player)
			ft_printf("%fdmap: no player\n", 2);
		else
			ft_printf("%fdmap: more than one player\n", 2);
	}
	else if (err == MAP_ERR_CLBLS)
		ft_printf("%fdmap: no collectibles\n", 2);
	else if (err == MAP_ERR_RECTLE)
	{
		ft_printf("%fdmap: not a rectangle (row %i)\n", 2, *(int *) p + 1);
		return (sl_error_credits(checks));
	}
	return (1);
}

int	sl_perr_map(int err, void *p, t_sl_map *checks)
{
	checks->err++;
	if (checks->err == 1)
		ft_printf("%fdError\n", 2);
	if (checks->err > 10 && err == MAP_ERR_RECTLE)
		return (sl_error_credits(checks));
	if (checks->err > 10)
		return (1);
	if (err == MAP_ERR_CHAR)
		ft_printf("%fdmap: unrecognized character '%c'\n", 2, *(char *) p);
	else if (err == MAP_ERR_HOLE)
		ft_printf("%fdmap: wall is not complete (row %i)\n", 2, *(int *)p + 1);
	else if (err == MAP_ERR_EXIT)
	{
		if (!checks->exit)
			ft_printf("%fdmap: no exit\n", 2);
		else
			ft_printf("%fdmap: more than one exit\n", 2);
	}
	return (sl_perr_map_2(err, p, checks));
}
