/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:51:14 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/11 17:42:04 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[])
{
	t_fds	fds;

	if (px_set_files(&fds, av[1], av[ac - 1]) == -1)
		return (-1);
}



// '-' not written anywhere
// '+' written somewhere

/* mem to free:
*/

/* fds to close:
	+fds->inf
	+fds->outf
*/
