/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_clear_animations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:13:32 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/05 17:10:12 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_amclear(t_sl_data *data, t_list **lst)
{
	t_list	*t;
	t_list	*temp;

	if (!lst)
		return ;
	t = *lst;
	while (t)
	{
		temp = t;
		mlx_destroy_image(data->mlx, t->content);
		t = t->next;
		free(temp);
	}
	free(lst);
}

static void	sl_clear_all_anims(t_sl_data *data)
{
	sl_amclear(data, data->am->k_mv_l);
	sl_amclear(data, data->am->k_mv_r);
}

// returns 1
int	sl_clear_animations(t_sl_data *data)
{
	if (!data->am)
		return (1);
	sl_clear_all_anims(data);
	free(data->am);
	data->am = NULL;
	return (1);
}
