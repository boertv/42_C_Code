/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:11:29 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/05 17:59:30 by bvercaem         ###   ########.fr       */
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
// from here: clear_da(data->map)			at init: data->map = NULL;
	if (sl_map_check(&data))
		return (sl_flush_all(&data));
	if (sl_mlx_init(&data))
		return (sl_flush_all(&data));
// from here: mlx_destroy(data->win)		at init: data->win = NULL;
	if (sl_load_texs(&data))
// from here: call sl_clear_texs			at init: data->tex = NULL;
// from here: call sl_clear_animations		at init: data->am = NULL;
		return (1);
	if (sl_init_map(&data))
// from here: clear_da(data->mask_cr)		at init: data->mask_cr = NULL;
// from here: call sl_clear_crs				at init: data->crs = NULL;
		return (1);
	sl_mlx_loop(&data);
// READ COMMENTS BEFORE PUSHING
}

// load all imgs (texs and animations) in one function, clear them in one too
//		(don't forget free(data->tex) and free(data->lib))

// MAKE SURE CHEATS IS OFF
// MAKE SURE MAKEFILE CFLAG IS STANDARD

// remove all .DS_Store and .vscode

//stuff to free;
//	- map
//	- masks
//	- textures
//	- window
//
//	- t_list crs
//		- every t_list
//		- every t_creature
//
//	- animations
//		- am_lib
//		- anim t_lists

//size of an mlx char:
//	- one char  = 10-22
// (actual height of normal char is 15, but print area (and artefacts) is 22)
//	- two chars = 20-22
