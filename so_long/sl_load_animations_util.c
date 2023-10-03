/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_animations_util.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:31:55 by bvercaem          #+#    #+#             */
/*   Updated: 2023/10/03 17:43:04 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// file = folder, except for ERR_LOADING, then it is frame which is freed
// returns 1
int	sl_perror_am(const char *file, int err)
{
	if (err == ERR_FOLDER)
		ft_printf("%fdno, or bad, folder '%s'\n", 2, file);
	else if (err == ERR_EMPTY)
		ft_printf("%fdno useable images in %s\n", 2, file);
	else if (err == ERR_LOADING)
	{
		ft_printf("%fdfailed to load %s\n", 2, file);
		free((void *) file);
	}
	else if (err == ERR_MALLOC)
		ft_printf("%fdmalloc failed while loading %s\n", 2, file);
	return (1);
}

// returns NULL and prints error if malloc failed
char	*sl_join_frame_name(const char *folder, int i)
{
	char	*frame;
	char	*bin;

	frame = ft_itoa(i);
	if (!frame)
	{
		sl_perror_am(folder, ERR_MALLOC);
		return (NULL);
	}
	bin = ft_strjoin(frame, ".xpm");
	free(frame);
	if (!bin)
	{
		sl_perror_am(folder, ERR_MALLOC);
		return (NULL);
	}
	frame = ft_strjoin(folder, bin);
	free(bin);
	if (!frame)
		sl_perror_am(folder, ERR_MALLOC);
	return (frame);
}
