/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:11:29 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/06 16:21:12 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_init_startup(t_sl_data *data)
{
	data->map = NULL;
	data->win = NULL;
	data->tex = NULL;
	data->am = NULL;
	data->mask_cr = NULL;
	data->crs = NULL;
}

int	main(int ac, char *av[])
{
	t_sl_data	data;

	if (ac != 2 || sl_file_check(av[1]))
		return (sl_print_errmsg(NULL, "please provide one '.ber' map-file", 1));
	sl_init_startup(&data);
	data.map = sl_create_map(av[1]);
	data.map_file = av[1];
	if (!data.map)
		return (sl_print_errno(av[1], 1));
	if (sl_map_check(&data))
		return (sl_flush_all(&data));
	if (sl_mlx_init(&data))
		return (sl_flush_all(&data));
	if (sl_load_texs(&data))
		return (sl_flush_all(&data));
	if (sl_init_map(&data))
		return (sl_flush_all(&data));
	sl_mlx_loop(&data);
// READ COMMENTS BEFORE PUSHING
}

// MAKE SURE CHEATS IS OFF
// MAKE SURE MAKEFILE CFLAG IS STANDARD
// remove all .DS_Store and .vscode

/*
		MEMORY IN USE:

[creator ft:]
	[mem address]			[clearing ft]			[what to initialise]

sl_create_map():
	char **data->map		ft_clear_da()			data->map = NULL;

sl_mlx_init():
	void *data->win			mlx_destroy_window()	data->win = NULL;

sl_load_texs():
	t_tex *data->tex		sl_clear_texs()			data->tex = NULL;
	t_amlib *data->am		sl_clear_animations()	data->am = NULL;

sl_init_map():
	char **data->mask_cr	ft_clear_da()			data->mask_cr = NULL;
	t_list **data->crs		sl_clear_crs()			data->crs = NULL;
*/

/*
		size of an mlx char:
	one char:	10-22
	two chars:	20-22
 (actual height of normal char is 15, but the print area (with artefacts) is 22)
*/
