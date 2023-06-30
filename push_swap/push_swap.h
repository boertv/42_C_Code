/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:49:25 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/30 14:53:52 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/legacy/libft.h"
# include "./libft/ft_printf/ft_printf.h"

typedef struct s_dlilist
{
	int					nb;
	size_t				index;
	struct s_dlilist	*next;
	struct s_dlilist	*prev;
}				t_dlilist;

// s = 1 only if all previous chunks are also sorted.
typedef struct s_chunk
{
	size_t			size;
	size_t			r;
	int				max;
	int				min;
	int				avg;
	char			s;
	struct s_chunk	*next;
}				t_chunk;

// print_front always contains 0.
typedef struct s_stack
{
	char		a;
	t_dlilist	*start;
	t_dlilist	*end;
	size_t		size;
	t_chunk		*chunks;
	int			max;
	int			min;
	t_dlilist	**print_front;
	t_dlilist	**print_back;
}				t_stack;

// changing these nbs might ruin some print optimisations.
# define OP_SA 1
# define OP_SB 2
# define OP_PA 3
# define OP_PB 4
# define OP_RA 5
# define OP_RB 6
# define OP_RRA 7
# define OP_RRB 8
# define OP_SS 11
# define OP_RR 12
# define OP_RRR 13

int			ps_initialise_stack(int ac, char *av[], t_stack *a, t_stack *b);
int			ps_initialise_print(t_stack *a, t_stack *b);
void		ps_set_null(t_stack *a, t_stack *b);
int			ps_isvalid(char *str);
int			ps_error(t_stack *a, t_stack *b);

t_dlilist	*ps_create_element(int nb);
int			ps_del_back(t_stack *s, short f);
int			ps_del_front(t_stack *s, short f);
int			ps_add_back(t_stack *s, t_dlilist *el);
int			ps_add_front(t_stack *s, t_dlilist *el);
int			ps_add_emptychunk(t_stack *s);
int			ps_del_chunk(t_stack *s);
int			ps_merge_chunks(t_stack *s);
t_chunk		*ps_get_last_chunk(t_chunk *start);

int			ps_swap(t_stack *s, t_stack *o, short p);
int			ps_push(t_stack *src, t_stack *dst, short p);
int			ps_rotate(t_stack *s, short p);
int			ps_rrotate(t_stack *s, short p);
int			ps_ss(t_stack *a, t_stack *b, short p);
int			ps_rr(t_stack *a, t_stack *b, short p);
int			ps_rrr(t_stack *a, t_stack *b, short p);

void		ps_print_compression(t_stack *s);
void		ps_print_trim(t_stack *s);
void		ps_print_optimising(t_stack *s);
int			ps_print_add_back(t_stack *s, t_dlilist *el);
void		ps_print_ops(t_stack *s);
void		ps_print_clear(t_stack *s);
int			ps_print_del(t_stack *s, t_dlilist *el);

int			ps_issorted(t_stack *s, short as, short c);
int			ps_ismaxmin(t_stack *s, short x, short c);
void		ps_isnewattribute(t_stack *s, int nb, t_chunk *chunk);
void		ps_isoldattribute(t_stack *s, int nb, t_chunk *chunk);
void		ps_addnewattribute(t_stack *s, int nb, t_chunk *chunk);

int			ps_small_sorts(t_stack *a, t_stack *b);
int			ps_fastest_push(t_stack *src, t_stack *dst, int nb);
ssize_t		ps_find_nbindex(t_stack *s, int nb);
int			ps_big_sort(t_stack *a, t_stack *b);
int			ps_set_indexes(t_stack *s);
int			ps_ischunkavg(t_stack *s);
int			ps_ispushdone(t_stack *src, char b);
int			ps_push_or_rotate(t_stack *src, t_stack *dst, short rr);
int			ps_rrotate_chunk_values(t_stack *src, t_stack *dst);
int			ps_rrotate_with_push(t_stack *src, t_stack *dst);
int			ps_check_push_result(t_stack *src, t_stack *dst);

#endif
