/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_execution_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:13:11 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/21 17:35:07 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// returns the new ptr, or NULL if malloc failed
char	**px_resize_malloc(char	**da)
{
	size_t	i;
	char	**new;

	i = 0;
	while (da[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	if (!new)
		return (NULL);
	new[i] = NULL;
	while (i-- > 0)
		new[i] = da[i];
	free(da);
	return (new);
}

static int	px_da_join_const(char **da, size_t i, const char *c)
{
	char 	*new;

	new = ft_strjoin(da[i], c);
	if (!new)
		return (1);
	free(da[i]);
	da[i] = new;
	return (0);
}

// joins da[i] + c + da[i + 1]. Then shifts the remaining strs and sets NULL
// returns 1 if bad input or ft_strjoin failed, else 0
// c ISN'T FREED
int	px_da_join(char **da, size_t i, const char *c)
{
	size_t	size;
	char	*new;

	size = 0;
	while (da && da[size] && size <= i)
		size++;
	if (!da || !da[size])
		return (1);
	if (c)
		if (px_da_join_const(da, i, c))
			return (1);
	new = ft_strjoin(da[i], da[i + 1]);
	if (!new)
		return (1);
	free(da[i]);
	free(da[i + 1]);
	da[i] = new;
	while (da[++i + 1])
		da[i] = da[i + 1];
	da[i] = NULL;
	return (0);
}
