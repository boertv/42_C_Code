/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:11:29 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/23 16:58:07 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_game_data	data;

	if (ac != 2)
	{
		write (STDERR_FILENO, "Please provide a map ,.ber, file\n", 33);
		return (1);
	}
	data.map = sl_create_map(av[1]);
	if (!data.map)
		return (sl_print_errno(av[1], 1));
	if (sl_map_check(&data))
	{
		ft_clear_da(data.map);
		return (1);
	}
// check map for solvabillity
// temp return:
ft_clear_da(data.map);
return (0);

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
}

//stuff to free;
//	- map
