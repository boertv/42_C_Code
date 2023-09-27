/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:13:24 by bvercaem          #+#    #+#             */
/*   Updated: 2023/09/27 17:43:41 by bvercaem         ###   ########.fr       */
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
# include "sl_creatures.h"

typedef struct s_sl_data
{
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
	char	**map;
	int		map_w;
	int		map_h;
	char	**mask_cr;
	int		plr[3];
	int		plr_size;
	int		mvs;
	int		clblt;
	int		clbls;
	int		cords[2];
	int		clock;
	int		msgtimer;
	int		immunetimer;
	int		end[2];
	t_tex	*tex;
	t_amlib	*am;
	t_list	**crs;
	char	*map_file;
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

typedef struct s_animation
{
	int		inter;
	void	**imgs;
}			t_animation;

typedef struct s_animation_lib
{
	t_animation	k_mv_r;
	t_animation	k_mv_l;
	t_animation	p_idle;
}				t_amlib;

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
int			sl_create_mask_cr(t_sl_data *data);
int			sl_render_map(t_sl_data *data);
void		sl_print_game_frame(t_sl_data *data, int color);
int			sl_search_map(t_sl_data *data, char c, int *x, int *y);
char		sl_getnb(t_sl_data *data, int x, int y, int dir);
int			sl_check_dir_wall(t_sl_data *data, int x, int y, int dir);
int			sl_create_color(int t, int r, int g, int b);
int			sl_cv_cdpx(int cord, char xy, int offset);
int			sl_print_rectangle(t_sl_data *data, int w, int h, int color);
void		sl_print_frame(t_sl_data *data, int w, int h, int color);
void		sl_print_midtext(t_sl_data *data, char *str, int y, int color);
void		sl_print_fullwin(t_sl_data *data, int bgcol, int txcol, char *msg);
void		sl_translate_xy_to_pixel(t_sl_data *data, int x, int y);
int			sl_print_tile(t_sl_data *data, int x, int y, int offset);
void		sl_put_imgs_tile(t_sl_data *data, int w, int h, void *img);
void		sl_print_wall(t_sl_data *data, int x, int y, int offset);
int			sl_print_mask_cr(t_sl_data *data, int x, int y);
void		sl_print_mvs(t_sl_data *data);
void		sl_print_clbl(t_sl_data *data);
void		sl_print_reset(t_sl_data *data);

int			sl_load_texs(t_sl_data *data);
void		*sl_load_sprite(t_sl_data *data, char *file, char **err);
int			sl_grow_plr(t_sl_data *data);
int			sl_shrink_plr(t_sl_data *data, int min);
void		sl_clear_sprs(t_sl_data *data);

void		sl_mlx_loop(t_sl_data *data);
int			sl_key_hook_hub(int key, t_sl_data *data);
int			sl_timed_loop(t_sl_data *data);
int			sl_end_hook(int key, t_sl_data *data);
int			sl_end_loop(t_sl_data *data);
int			sl_move_cr(t_sl_data *data, int *x, int *y, char dir);
void		sl_move_knights(t_sl_data *data);
int			sl_upd_clbl(t_sl_data *data, int x, int y);
int			sl_upd_crdir(t_sl_data *data, int *x, int *y, char dir);
int			sl_upd_plmv(t_sl_data *data, int x, int y);

void		sl_victory_screen(t_sl_data *data);
void		sl_death_screen(t_sl_data *data);
void		sl_put_answer_indicator(t_sl_data *data, int item);
int			sl_reset(t_sl_data *data);
int			sl_flush_all(t_sl_data *data);
int			sl_flush_loop(t_sl_data *data);

int			sl_print_errno(char *msg, int rtrn);
int			sl_print_errmsg(t_sl_map *checks, char *msg, int rtrn);
int			sl_perr_map(int err, void *p, t_sl_map *checks);
int			sl_error_credits(t_sl_map *checks);

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_R 15
# define KEY_C 8
# define KEY_G 5
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
# define MAP_CHARS "01PCEK"

# define DIR_UP 'u'
# define DIR_DOWN 'd'
# define DIR_LEFT 'l'
# define DIR_RIGHT 'r'

# define BG_COL 0
# define CLBL_COL 3302410
# define VICS_COL 1681036820
# define UI_COL 6597170
# define MSG_COL 16777215
# define COL_WHITE 16777215
# define COL_GREY 5263440
# define COL_DGREY 9868950
# define COL_GREEN 6597170
# define COL_DGREEN 3302410
# define COL_RED 13120030
# define COL_LRED 9843250
# define COL_DRED 9838080
# define COL_PURPLE 13107455
# define COL_BLACK 0
# define COL_COPPER 12088115

# define SL_CHEATS 0
# define SL_IMMUNETMR 150

# define MAP_ERR_HOLE 1
# define MAP_ERR_CHAR 2
# define MAP_ERR_EXIT 3
# define MAP_ERR_PLAYER 4
# define MAP_ERR_CLBLS 5
# define MAP_ERR_RECTLE 6

#endif
