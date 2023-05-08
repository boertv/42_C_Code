/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:04:22 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/08 18:07:04 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_nb(char *to_print, t_flag *flag, t_nb_attr *nb, int *mlen)
{
	ft_strlcpy(to_print, flag->sform, *mlen - flag->fw - flag->pr + 1);
}
