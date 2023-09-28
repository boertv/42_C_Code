/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_animations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:29:25 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/28 17:13:53 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// file = folder, except for ERR_LOADING
static int	sl_perror_am(char *file, int err)
{
	if (err == ERR_FOLDER)
		ft_printf("%fdno, or bad, folder '%s'\n", 2, file);
	else if (err == ERR_EMPTY)
		ft_printf("%fdno useable images in %s\n", 2, file);
	else if (err == ERR_LOADING)
	{
		ft_printf("%fdfailed to load %s\n", 2, file);
		free(file);
	}
	else if (err == ERR_MALLOC)
		ft_printf("%fdmalloc failed while loading %s\n", 2, file);
	return (err);
}

// returns 1 if no folder, 2 if no imgs found, 3 if mlx loading error,
//	4 if malloc error, else 0
// prints error msgs
static int	sl_amload(t_sl_data *data, const char *folder, t_list **am)
{
	char	*temp;
	char	*bin;
	void	*img;
	t_list	*new;
	int		i;

	if (access(folder, R_OK))
		return (sl_perror_am(folder, ERR_FOLDER));
	am = malloc(sizeof(t_list *));
	if (!am)
		return (sl_perror_am(folder, ERR_MALLOC));
	*am = NULL;
	i = 0;
	while (1)
// add condition !!!!!!!?
	{
		bin = ft_itoa(i);
		if (!bin)
			return (sl_perror_am(folder, ERR_MALLOC));
		temp = ft_strjoin(folder, bin);
		free(bin);
		if (!temp)
			return (sl_perror_am(folder, ERR_MALLOC));
		if (access(temp, R_OK))
			break ;
		img = mlx_xpm_file_to_image(data->mlx, temp, &data->tex->width, &data->tex->height);
		if (!img)
			return (sl_perror_am(temp, ERR_LOADING));
		new = ft_lstnew(img);
		if (!new)
		{
			free(temp);
			mlx_destroy_image(data->mlx, img);
			return (sl_perror_am(folder, ERR_MALLOC));
		}
		ft_lstadd_back(am, new);
		free(temp);
		i++;
	}
	free(temp);
	if (!i)
		return (sl_perror_am(folder, ERR_EMPTY));
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
	data->am->k_mv_l = NULL;
	data->am->k_mv_r = NULL;
	if (sl_amload(data, AM_KNIGHT_MV_L, data->am->k_mv_l))
		return (sl_clear_animations(data));
	if (sl_amload(data, AM_KNIGHT_MV_R, data->am->k_mv_r))
		return (sl_clear_animations(data));
	return (0);
}