/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:49:06 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/30 13:25:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"
# include "./libft/get_next_line/get_next_line.h"


int	ps_parser(t_stack *a, t_stack *b, char * stdout);
int	ps_bonus_out(t_stack *a, t_stack *b, const char *out, int rtrn);

#endif
