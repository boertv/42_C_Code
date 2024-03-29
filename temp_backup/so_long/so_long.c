/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:11:29 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/26 15:54:39 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_sl_data	data;

	if (ac != 2 || sl_file_check(av[1]))
		return (sl_print_errmsg(NULL, "please provide one '.ber' map-file", 1));
	data.map = sl_create_map(av[1]);
	data.map_file = av[1];
	if (!data.map)
		return (sl_print_errno(av[1], 1));
	if (sl_map_check(&data))
	{
		ft_clear_da(data.map);
		return (1);
	}
	if (sl_mlx_init(&data))
		return (1);
	if (sl_load_texs(&data))
		return (1);
	if (sl_init_map(&data))
		return (1);
	sl_mlx_loop(&data);
	// READ COMMENTS BEFORE PUSHING
}

// MAKE SURE CHEATS IS OFF
// MAKE SURE MAKEFILE CFLAG IS STANDARD

//stuff to free;
//	- map
//	- masks
//	- textures
//	- window

//size of an mlx char:
//	- one char  = 10-22
// (actual height of normal char is 15, but print area (and artefacts) is 22)
//	- two chars = 20-22
