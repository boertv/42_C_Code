/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:48:01 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/05 17:13:19 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// all here just return 0 for francinette
// returns -1 on error, else 0
short	ft_flag_errors(t_flag *pflag)
{
	return (0);
	if (pflag->fw == -1)
		return (-1);
	if (pflag->pr == -1)
		return (-1);
	if (pflag->zs && pflag->lj)
		return (ft_error_minone("zero && lj", "flag_errors", NULL));
	if (pflag->sp && pflag->pl)
		return (ft_error_minone("space && plus", "flag_errors", NULL));
	return (0);
}

// returns -1 on error, else 0
short	ft_flag_str(t_flag *pflag)
{
	return (0);
	if (pflag->zs)
		return (ft_error_minone("zeroes", "flag_str", NULL));
	if (pflag->pl)
		return (ft_error_minone("plus", "flag_str", NULL));
	if (pflag->sp)
		return (ft_error_minone("space", "flag_str", NULL));
	if (pflag->ht)
		return (ft_error_minone("hashtag", "flag_str", NULL));
	return (0);
}

// returns -1 on error, else 0
short	ft_flag_char(t_flag *pflag)
{
	return (0);
	if (pflag->pr)
		return (ft_error_minone("precision", "flag_char", NULL));
	if (ft_flag_str(pflag) == -1)
		return (ft_error_minone("flag_str", "flag_char", NULL));
	return (0);
}

// returns -1 on error, else 0
short	ft_flag_nb(t_flag *pflag, t_nb_attr *pnb)
{
	return (0);
	if (pnb->baselen == 10)
		if (pflag->ht)
			return (ft_error_minone("hashtag for int", "flag_nb", NULL));
	if (!pnb->s && (pflag->sp || pflag->pl))
		return (ft_error_minone("space or plus for unsigned", "flag_nb", NULL));
	return (0);
}
