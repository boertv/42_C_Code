/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_textures.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:18:27 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/01 19:11:06 by bvercaem         ###   ########.fr       */
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

# define TILE_WIDTH 32
# define TILE_HEIGHT 32
# define HEAD 0
# define TAIL 0
# define SHOULDER 0
# define INDENT 0

# define FACE_FRONT 'f'
# define FACE_BACK 'b'
# define FACE_LEFT 'l'
# define FACE_RIGHT 'r'

/* !!MAKE SURE ALL OF THESE EXIST!! */
# define TEX_EMPTY "./textures/empty.xpm"
# define TEX_WALL "./textures/wall.xpm"
# define TEX_CLBL_NEW "./textures/clbl_new.xpm"
# define TEX_CLBL_OLD "./textures/clbl_old.xpm"
# define TEX_EXIT_CLSD "./textures/exit_clsd.xpm"
# define TEX_EXIT_OPEN "./textures/exit_open.xpm"
# define TEX_PLR_FRONT "./textures/plr_front.xpm"
# define TEX_PLR_BACK "./textures/plr_back.xpm"
# define TEX_PLR_LEFT "./textures/plr_left.xpm"
# define TEX_PLR_RIGHT "./textures/plr_right.xpm"

#endif
