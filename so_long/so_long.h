/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:13:24 by bvercaem          #+#    #+#             */
/*   Updated: 2023/08/31 19:12:59 by bvercaem         ###   ########.fr       */
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
	int		win_w;
	int		win_h;
	char	**map;
	size_t	map_w;
	size_t	map_h;
	char	**mask_cr;
	int		plr[3];
	int		cords[2];
	int		mvs;
	int		clbls;
	t_tex	*tex;
}			t_sl_data;

typedef struct s_sl_map
{
	int		exit;
	int		player;
	int		err;
}			t_sl_map;

typedef struct s_sl_list
{
	int					x;
	int					y;
	struct s_sl_list	*next;
	struct s_sl_list	*prev;
}					t_sl_list;

typedef struct s_sl_slv
{
	int			col;
	int			exi;
	t_sl_list	*old;
	t_sl_list	*cur;
	t_sl_list	*new;
}				t_sl_slv;

int			sl_file_check(char *file);
char		**sl_create_map(char *file);
int			sl_map_check(t_sl_data *data);
int			sl_map_solvable(t_sl_data *data);

void		sl_solv_init(t_sl_slv *slv, t_sl_data *data);
t_sl_list	*sl_list_create(int x, int y);
int			sl_list_addback(t_sl_list **last, t_sl_list *new);
t_sl_list	*sl_list_clear(t_sl_list *last);
int			sl_list_search(t_sl_list *last, int x, int y);

int			sl_mlx_init(t_sl_data *data);
int			sl_init_map(t_sl_data *data);
int			sl_render_map(t_sl_data *data);
int			sl_search_map(t_sl_data *data, char c, int *x, int *y);
int			sl_create_color(int t, int r, int g, int b);
void		sl_translate_xy_to_pixel(t_sl_data *data, int x, int y);
int			sl_print_tile(t_sl_data *data, int x, int y, int offset);
int			sl_print_mask_cr(t_sl_data *data, int x, int y);
void		sl_print_mvs(t_sl_data *data);

int			sl_load_texs(t_sl_data *data);
void		sl_clear_sprs(t_sl_data *data);

void		sl_mlx_loop(t_sl_data *data);
int			sl_key_hook_hub(int key, t_sl_data *data);
int			sl_move_cr(t_sl_data *data, int *x, int *y, char dir);
int			sl_upd_clbl(t_sl_data *data, int x, int y);
int			sl_upd_pldir(t_sl_data *data, int x, int y, char dir);
int			sl_upd_plmv(t_sl_data *data, int x, int y);

int			sl_flush_all(t_sl_data *data);
int			sl_flush_loop(t_sl_data *data);

int			sl_print_errno(char *msg, int rtrn);
int			sl_print_msg(char *msg, int rtrn);
int			sl_perr_map(int err, void *p, t_sl_map *checks);

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

# define WALL '1'
# define EMPTY '0'
# define CLBL_NEW 'C'
# define CLBL_OLD 'D'
# define EXIT_CLSD 'E'
# define EXIT_OPEN 'O'
# define PLAYER 'P'

# define DIR_UP 'u'
# define DIR_DOWN 'd'
# define DIR_LEFT 'l'
# define DIR_RIGHT 'r'

# define MAP_CHARS "01PCE"

# define MAP_ERR_HOLE 1
# define MAP_ERR_CHAR 2
# define MAP_ERR_EXIT 3
# define MAP_ERR_PLAYER 4
# define MAP_ERR_CLBLS 5

#endif
