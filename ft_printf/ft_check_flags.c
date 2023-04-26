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
static int	ft_check_errors(char *sub_format)
{
	if (ft_field_width(sub_format) == -1)
		return (-1);
	if (ft_precision(sub_format) == -1)
		return (-1);
	if (ft_left_just(sub_format) == -1)
		return (-1);
	if (ft_space(sub_format) == -1)
		return (-1);
	return (0);
}

int	ft_check_char(char *sub_format)
{
	if (ft_precision(sub_format))
		return (-1);
	if (ft_zeroes(sub_format))
		return (-1);
	if (ft_plus(sub_format))
		return (-1);
	if (ft_space(sub_format))
		return (-1);
	if (ft_hashtag(sub_format))
		return (-1);
	if (ft_check_errors(sub_format) == -1)
		return (-1);
	return (0);
}

int	ft_check_int(char *sub_format)
{
	if (ft_hashtag(sub_format))
		return (-1);
	if (ft_check_errors(sub_format) == -1)
		return (-1);
	return (0);
}
