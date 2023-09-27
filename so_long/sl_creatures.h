/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_creatures.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:36:16 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/27 17:19:17 by bvercaem         ###   ########.fr       */
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
	void	*anim;
}			t_creature;

# define CR_CHARS "Kk"

# define KNIGHT_R 'K'
# define KNIGHT_L 'k'

# define KNIGHT 'K'
# define DIR_K "rl"

# define WIZARD 'W'
# define DIR_W "ud"

#endif
