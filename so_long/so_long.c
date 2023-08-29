/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:11:29 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/29 18:47:23 by bvercaem         ###   ########.fr       */
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
		ft_clear_da(data.map);
		return (1);
	}
	if (sl_mlx_init(&data))
		return (1);
	if (sl_load_texs(&data))
		return (1);
	sl_render_map(&data);

// temp loop:
mlx_key_hook(data.win, sl_key_hook_hub, (void *) &data);
mlx_loop(data.mlx);

// temp return:
sl_clear_sprs(&data);
ft_clear_da(data.map);
return (0);
}

//stuff to free;
//	- map
//	- textures
//	- window
