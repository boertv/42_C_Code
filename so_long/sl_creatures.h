/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_creatures.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:36:16 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/28 19:17:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_CREATURES_H
# define SL_CREATURES_H

# include "so_long.h"

typedef struct s_creature
{
	char	type;
	int		cd[2];
	char	*dir;
	int		dir_i;
	int		offset;
	t_list	*frame;
}				t_creature;

# define CR_CHARS "Kk"

// knight in an animation cycle == 'k'?
# define KNIGHT 'K'
# define DIR_K "rl"
# define OFF_K_START 60
# define OFF_K_INC 5

# define WIZARD 'W'
# define DIR_W "ud"

#endif