/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:48:01 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/08 16:59:25 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// returns -1 on error, else 0
short	ft_flag_errors(t_flag *flag)
{
	if (flag->fw == -1)
		return (-1);
	if (flag->pr == -1)
		return (-1);
	return (0);
}

// for now just returns 0 for francinette
// returns -1 on error, else 0
short	ft_flag_str(t_flag *flag)
{
	return (0);
	if (flag->zs)
		return (ft_error_minone("zeroes", NULL, NULL));
	if (flag->pl)
		return (ft_error_minone("plus", NULL, NULL));
	if (flag->sp)
		return (ft_error_minone("space", NULL, NULL));
	if (flag->ht)
		return (ft_error_minone("hashtag", NULL, NULL));
	return (0);
}

// for now just returns 0 for francinette
// returns -1 on error, else 0
short	ft_flag_char(t_flag *flag)
{
	return (0);
	if (flag->pr)
		return (ft_error_minone("precision", "flag_char", NULL));
	if (ft_flag_str(flag))
		return (ft_error_minone(NULL, "flag_char", NULL));
	return (0);
}

// for now just returns 0 for francinette
// returns -1 on error, else 0
short	ft_flag_nb(t_flag *flag, t_nb_attr *pnb)
{
	return (0);
	if (pnb->baselen == 10)
		if (flag->ht)
			return (ft_error_minone("hashtag for int", "flag_nb", NULL));
	if (!pnb->s && (flag->sp || flag->pl))
		return (ft_error_minone("space or plus for unsigned", "flag_nb", NULL));
	return (0);
}
