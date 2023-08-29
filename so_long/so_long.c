/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:11:29 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/29 15:50:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_sl_data	data;

	if (ac != 2 || sl_file_check(av[1]))
		return (sl_print_msg("please provide one '.ber' map-file", 1));
	data.map = sl_create_map(av[1]);
	if (!data.map)
		return (sl_print_errno(av[1], 1));
	if (sl_map_check(&data))
	{
// check map for solvabillity in sl_map_check
//		run over the map with two linked lists, one current positions, one previous ones
		ft_clear_da(data.map);
		return (1);
	}
ft_printf("map checked\n");
	if (sl_load_texs(&data))
		return (1);
ft_printf("loaded textures\n");
	if (sl_mlx_init(&data))
		return (1);
ft_printf("initialized mlx\n");
	sl_render_map(&data);

// temp return:
sl_clear_sprs(&data);
ft_clear_da(data.map);
return (0);
}

//stuff to free;
//	- map
//	- textures
