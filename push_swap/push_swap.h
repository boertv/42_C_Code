/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:49:25 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/09 16:35:06 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/legacy/libft.h"
# include "./libft/ft_printf/ft_printf.h"

typedef struct s_dlilist
{
	int					nb;
	struct s_dlilist	*next;
	struct s_dlilist	*prev;
}				t_dlilist;

typedef struct s_stack
{
	t_dlilist	*start;
	t_dlilist	*end;
	size_t		size;
	int			max;
	int			min;
	int			avg;
	int			cta;
}				t_stack;

int			ps_initialise_stack(int ac, char *av[], t_stack *a, t_stack *b);
t_dlilist	*ps_create_element(int nb);
void		ps_swap(t_stack *a, char c);
void		ps_ss(t_stack *a, t_stack *b);
void		ps_push(t_stack *src, t_stack *dst, char c);
void		ps_rotate(t_stack *a, char c);
void		ps_rr(t_stack *a, t_stack *b);
void		ps_rrotate(t_stack *a, char c);
void		ps_rrr(t_stack *a, t_stack *b);
void		ps_fastest_push(t_stack *src, t_stack *dst, int nb, char csrc);
int			ps_error(t_stack *a, t_stack *b);
int			ps_del_back(t_stack *a, short f);
int			ps_del_front(t_stack *a, short f);
int			ps_add_back(t_stack *a, t_dlilist *el);
int			ps_add_front(t_stack *a, t_dlilist *el);
int			ps_issorted(t_stack *a, short as);
int			ps_ismaxmin(t_stack *a, short x);
int			ps_isavg(t_stack *a);
int			ps_closesttoavg(t_stack *a);
void		ps_isnewattribute(t_stack *a, int nb);
void		ps_isoldattribute(t_stack *a, int nb);
void		ps_addnewattribute(t_stack *a, int nb);

void		ps_small_sorts(t_stack *a, t_stack *b, int size);

#endif
