/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_animations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:29:25 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/03 17:42:45 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sl_addframe(t_sl_data *da, t_list **anim, char *fm, const char *fld)
{
	void	*img;
	t_list	*new;

	img = mlx_xpm_file_to_image(da->mlx, fm, &da->tex->w, &da->tex->h);
	if (!img)
		return (sl_perror_am(fm, ERR_LOADING));
	free(fm);
	new = ft_lstnew(img);
	if (!new)
	{
		mlx_destroy_image(da->mlx, img);
		return (sl_perror_am(fld, ERR_MALLOC));
	}
	ft_lstadd_back(anim, new);
	return (0);
}

// returns 1 on error: no folder, no frames, bad mlx load, malloc
// prints error msgs
static int	sl_amload(t_sl_data *data, const char *folder, t_list **animation)
{
	char	*frame;
	int		i;

	if (access(folder, R_OK))
		return (sl_perror_am(folder, ERR_FOLDER));
	i = 0;
	while (i <= SL_FRAME_LIM)
	{
		frame = sl_join_frame_name(folder, i);
		if (!frame)
			return (1);
		if (access(frame, R_OK))
			break ;
		if (sl_addframe(data, animation, frame, folder))
			return (1);
		i++;
	}
	free(frame);
	if (!i)
		return (sl_perror_am(folder, ERR_EMPTY));
	return (0);
}

static int	sl_ams_mallocs(t_sl_data *data)
{
	data->am->k_mv_l = NULL;
	data->am->k_mv_r = NULL;
	data->am->k_mv_l = malloc(sizeof(t_list *));
	if (!data->am->k_mv_l)
	{
		ft_printf("%fdmalloc failed while loading animations\n", 2);
		return (1);
	}
	*data->am->k_mv_l = NULL;
	data->am->k_mv_r = malloc(sizeof(t_list *));
	if (!data->am->k_mv_r)
	{
		free(data->am->k_mv_l);
		ft_printf("%fdmalloc failed while loading animations\n", 2);
		return (1);
	}
	*data->am->k_mv_r = NULL;
	return (0);
}

// returns 1 for an error
int	sl_load_animations(t_sl_data *data)
{
	data->am = malloc (sizeof(t_amlib));
	if (!data->am)
	{
		ft_printf("%fdmalloc failed while loading animations\n", 2);
		return (1);
	}
	if (sl_ams_mallocs(data))
		return (1);
	if (sl_amload(data, AM_KNIGHT_MV_L, data->am->k_mv_l))
		return (sl_clear_animations(data));
	if (sl_amload(data, AM_KNIGHT_MV_R, data->am->k_mv_r))
		return (sl_clear_animations(data));
	return (0);
}
