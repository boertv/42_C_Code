/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_textures.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:18:27 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/26 17:04:41 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_TEXTURES_H
# define SL_TEXTURES_H

typedef struct s_tex
{
	void	*floor1;
	void	*floor2;
	void	*floor3;
	void	*floor4;
	void	*floor5;
	void	*floor_edge;
	void	*wall;
	void	*wall_clbl;
	void	*wall_old;
	void	*clbl_base;
	void	*ban_r;
	void	*ban_g;
	void	*ban_b;
	void	*ban_y;
	void	*clbl_new;
	void	*clbl_old;
	void	*exit_clsd;
	void	*exit_open;
	void	*plr_front;
	void	*plr_back;
	void	*plr_left;
	void	*plr_right;
	void	*knight_l;
	void	*knight_r;
	int		width;
	int		height;
}				t_tex;

# define TILE_WIDTH 64
# define TILE_HEIGHT 64
# define TLS 32
# define HEAD 70
# define TAIL 45
# define SHOULDER 25
# define INDENT 25

# define FACE_FRONT 'f'
# define FACE_BACK 'b'
# define FACE_LEFT 'l'
# define FACE_RIGHT 'r'

/* !!MAKE SURE ALL OF THESE EXIST!! */
# define TEX_FLOOR1 "./textures/floor_1_32.xpm"
# define TEX_FLOOR2 "./textures/floor_2_32.xpm"
# define TEX_FLOOR3 "./textures/floor_3_32.xpm"
# define TEX_FLOOR4 "./textures/floor_4_32.xpm"
# define TEX_FLOOR5 "./textures/floor_5_32.xpm"
# define TEX_FLOOR_EDGE "./textures/floor_edge_32.xpm"
# define TEX_WALL "./textures/wall_mid_32.xpm"
# define TEX_BAN_R "./textures/wall_banner_red_32.xpm"
# define TEX_BAN_G "./textures/wall_banner_green_32.xpm"
# define TEX_BAN_B "./textures/wall_banner_blue_32.xpm"
# define TEX_BAN_Y "./textures/wall_banner_yellow_32.xpm"
# define TEX_CLBL_NEW "./textures/floor_slime_32.xpm"
# define TEX_CLBL_OLD "./textures/floor_leftover_32.xpm"
# define TEX_CLBLWALL_NEW "./textures/wall_goo_32.xpm"
# define TEX_CLBLWALL_OLD "./textures/wall_hole_32.xpm"
# define TEX_CLBLWALL_FLOOR "./textures/wall_goo_base_32.xpm"
# define TEX_EXIT_CLSD "./textures/floor_hole_64.xpm"
# define TEX_EXIT_OPEN "./textures/floor_ladder_64.xpm"

# define TEX_KNIGHT_L "./textures/knight_left_64.xpm"
# define TEX_KNIGHT_R "./textures/knight_right_64.xpm"

# define TEX_PLR_FRONT_16 "./textures/slime_front_16.xpm"
# define TEX_PLR_BACK_16 "./textures/slime_back_16.xpm"
# define TEX_PLR_LEFT_16 "./textures/slime_left_16.xpm"
# define TEX_PLR_RIGHT_16 "./textures/slime_right_16.xpm"
# define TEX_PLR_FRONT_32 "./textures/slime_front_32.xpm"
# define TEX_PLR_BACK_32 "./textures/slime_back_32.xpm"
# define TEX_PLR_LEFT_32 "./textures/slime_left_32.xpm"
# define TEX_PLR_RIGHT_32 "./textures/slime_right_32.xpm"
# define TEX_PLR_FRONT_48 "./textures/slime_front_48.xpm"
# define TEX_PLR_BACK_48 "./textures/slime_back_48.xpm"
# define TEX_PLR_LEFT_48 "./textures/slime_left_48.xpm"
# define TEX_PLR_RIGHT_48 "./textures/slime_right_48.xpm"
# define TEX_PLR_FRONT_64 "./textures/slime_front_64.xpm"
# define TEX_PLR_BACK_64 "./textures/slime_back_64.xpm"
# define TEX_PLR_LEFT_64 "./textures/slime_left_64.xpm"
# define TEX_PLR_RIGHT_64 "./textures/slime_right_64.xpm"

#endif
