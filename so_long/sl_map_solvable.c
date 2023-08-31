/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_solvable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:16:23 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/31 14:36:49 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// mallocs the first element
static t_sl_list	*sl_solv_start(t_sl_data *data)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (data->map[y][x] != 'P')
	{
		x++;
		if (!data->map[0][x])
		{
			x = 1;
			y++;
		}
	}
	return (sl_list_create(x, y));
}

// returns 0 if tile can be added
// updates col and exi
static int	sl_check_tile(t_sl_data *data, t_sl_slv *slv, int x, int y)
{
	if (data->map[y][x] == '1')
		return (1);
	if (sl_list_search(slv->old, x, y))
		return (1);
	if (sl_list_search(slv->new, x, y))
		return (1);
	if (data->map[y][x] == 'C')
		slv->col--;
	else if (data->map[y][x] == 'E')
		slv->exi--;
	return (0);
}

static int	sl_add_neighbours(t_sl_data *data, t_sl_slv	*slv, t_sl_list *el)
{
	int	x;
	int	y;

	x = el->x - 1;
	y = el->y;
	if (!sl_check_tile(data, slv, x, y))
		if (sl_list_addback(&slv->new, sl_list_create(x, y)))
			return (1);
	x = el->x + 1;
	if (!sl_check_tile(data, slv, x, y))
		if (sl_list_addback(&slv->new, sl_list_create(x, y)))
			return (1);
	x = el->x;
	y = el->y - 1;
	if (!sl_check_tile(data, slv, x, y))
		if (sl_list_addback(&slv->new, sl_list_create(x, y)))
			return (1);
	y = el->y + 1;
	if (!sl_check_tile(data, slv, x, y))
		if (sl_list_addback(&slv->new, sl_list_create(x, y)))
			return (1);
	return (0);
}

static int	sl_solv_return(t_sl_slv *slv)
{
	sl_list_clear(slv->old);
	sl_list_clear(slv->cur);
	sl_list_clear(slv->new);
	if (!slv->col && !slv->exi)
		return (0);
	ft_printf("%fdmap is not solvable: ", 2);
	if (slv->col == 1 && !slv->exi)
		ft_printf("%fdone collectible is unreachable\n", 2);
	else if (slv->col && !slv->exi)
		ft_printf("%fd%i collectibles are unreachable\n", 2, slv->col);
	if (slv->col == 1 && slv->exi)
		ft_printf("%fdone collectible", 2);
	else if (slv->col && slv->exi)
		ft_printf("%fd%i collectibles", 2, slv->col);
	if (slv->col && slv->exi)
		ft_printf("%fd and the exit are unreachable\n", 2);
	else if (slv->exi)
		ft_printf("%fdexit is unreachable\n", 2);
	return (1);
}

// returns 1 if malloc failed or list is unsolvable
// (ptrs always point at the last element)
int	sl_map_solvable(t_sl_data *data)
{
	t_sl_slv	slv;
	t_sl_list	*temp;

	sl_solv_init(&slv, data);
	slv.cur = sl_solv_start(data);
	if (!slv.cur)
		return (1);
	while (slv.cur)
	{
		temp = slv.cur;
		while (temp)
		{
			if (sl_add_neighbours(data, &slv, temp))
				break ;
			temp = temp->prev;
		}
		if (temp)
			break ;
		slv.old = sl_list_clear(slv.old);
		slv.old = slv.cur;
		slv.cur = slv.new;
		slv.new = NULL;
	}
	return (sl_solv_return(&slv));
}
