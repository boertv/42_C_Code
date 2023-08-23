/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:18:13 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/23 15:48:48 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// doesn't free anything mind you.
int	sl_print_errno(char *msg, int rtrn)
{
	write (STDERR_FILENO, "so_long: ", 9);
	perror(msg);
	return (rtrn);
}

int	sl_print_msg(char *msg, int rtrn)
{
	write (STDERR_FILENO, "so_long: ", 9);
	write (STDERR_FILENO, msg, ft_strlen(msg));
	write (STDERR_FILENO, "\n", 1);
	return (rtrn);
}
