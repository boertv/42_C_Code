/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_textures.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:18:27 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/29 17:18:51 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_TEXTURES_H
# define SL_TEXTURES_H

typedef struct s_tex
{
	void	*empty;
	void	*wall;
	void	*clbl_new;
	void	*clbl_old;
	void	*exit_clsd;
	void	*exit_open;
	void	*plr_front;
	void	*plr_back;
	void	*plr_left;
	void	*plr_right;
	int		width;
	int		height;
}				t_tex;

# define SL_TILE_WIDTH 32
# define SL_TILE_HEIGHT 32
# define SL_HEAD 0
# define SL_SHOULDER 0

/* !!MAKE SURE ALL OF THESE EXIST!! */
# define SL_TEX_EMPTY "./textures/empty.xpm"
# define SL_TEX_WALL "./textures/wall.xpm"
# define SL_TEX_CLBL_NEW "./textures/clbl_new.xpm"
# define SL_TEX_CLBL_OLD "./textures/clbl_old.xpm"
# define SL_TEX_EXIT_CLSD "./textures/exit_clsd.xpm"
# define SL_TEX_EXIT_OPEN "./textures/exit_open.xpm"
# define SL_TEX_PLR_FRONT "./textures/plr_front.xpm"
# define SL_TEX_PLR_BACK "./textures/plr_back.xpm"
# define SL_TEX_PLR_LEFT "./textures/plr_left.xpm"
# define SL_TEX_PLR_RIGHT "./textures/plr_right.xpm"

#endif
