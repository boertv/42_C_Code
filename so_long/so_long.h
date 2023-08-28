/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:13:24 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/28 16:28:15 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "mlx/mlx.h"
# include "libft/legacy/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"

# include "sl_textures.h"

typedef struct s_sl_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		clbls;
	t_tex	*tex;
}			t_sl_data;

typedef struct s_sl_map
{
	size_t	width;
	int		exit;
	int		player;
	int		err;
}			t_sl_map;

typedef struct s_sl_tile
{
	int	x;
	int	y;
}		t_sl_tile;

typedef struct s_sl_list
{
	t_sl_tile		*tilp;
	struct s_list	*next;
	struct s_list	*prev;
}					t_sl_list;


int		sl_file_check(char *file);
char	**sl_create_map(char *file);
int		sl_map_check(t_sl_data *data);

int		sl_print_errno(char *msg, int rtrn);
int		sl_print_msg(char *msg, int rtrn);
int		sl_perr_map(int err, void *p, t_sl_map *checks);

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_CTR 256
# define KEY_SHFT 257
# define KEY_TAB 48
# define KEY_SPC 49
# define KEY_ENTR 36
# define KEY_RTRN 51

# define MAP_CHARS "01PCE"

# define MAP_ERR_HOLE 1
# define MAP_ERR_CHAR 2
# define MAP_ERR_EXIT 3
# define MAP_ERR_PLAYER 4
# define MAP_ERR_CLBLS 5

#endif
