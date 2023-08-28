/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_textures.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:18:27 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/28 16:47:51 by bvercaem         ###   ########.fr       */
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
	int		heigth;
}				t_tex;

# define SL_WIDTH 32;
# define SL_HEIGTH 32;

#endif
