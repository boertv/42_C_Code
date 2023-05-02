/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:48:01 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/24 13:49:18 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// all functions here return -1 on error
static int	ft_check_errors(char *sform)
{
	if (ft_field_width(sform) == -1)
		return (-1);
	if (ft_precision(sform) == -1)
		return (-1);
	if (ft_left_just(sform) == -1)
		return (-1);
	if (ft_space(sform) == -1)
		return (-1);
	return (0);
}

int	ft_check_char(char *sform)
{
	if (ft_precision(sform))
		return (-1);
	if (ft_zeroes(sform))
		return (-1);
	if (ft_plus(sform))
		return (-1);
	if (ft_space(sform))
		return (-1);
	if (ft_hashtag(sform))
		return (-1);
	if (ft_check_errors(sform) == -1)
		return (-1);
	return (0);
}

int	ft_check_nb(char *sform, int baselen, int sign)
{
	if (baselen == 10)
		if (ft_hashtag(sform))
			return (-1);
	if (!sign)
		if (ft_space(sform) || ft_plus(sform))
			return (-1);
	if (ft_check_errors(sform) == -1)
		return (-1);
	return (0);
}
