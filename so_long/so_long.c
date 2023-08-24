/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:11:29 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/24 16:58:49 by bvercaem         ###   ########.fr       */
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
// check map for solvabillity in sl_map_check
//		run over the map with two linked lists, one current positions, one previous ones

// temp return:
ft_clear_da(data.map);
return (0);

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
}

//stuff to free;
//	- map
