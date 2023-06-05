/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:49:25 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/05 17:43:05 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./libft/legacy/libft.h"
# include "./libft/ft_printf/ft_printf.h"

typedef	struct	s_stack
{
	int		*array;
	size_t	size;
}				*t_stack;

int		ps_initialise_stack(int ac, char *av[], t_stack a, t_stack b);
void	ps_swap(t_stack a);
void	ps_push(t_stack src, t_stack dst);
void	ps_rotate(t_stack a);
void	ps_rrotate(t_stack a);
void	ps_shiftup(t_stack a);
void	ps_shiftdown(t_stack a);
int		ps_error(void);

#endif
