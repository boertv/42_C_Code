/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:47:57 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/30 13:07:51 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ps_bonus_out(t_stack *a, t_stack *b, const char *out, int rtrn)
{
	while (ps_del_back(a, 1) || ps_del_back(b, 1))
		(void)a;
	while (ps_del_chunk(a) || ps_del_chunk(b))
		(void)a;
	ps_print_clear(a);
	if (out)
		ft_printf("%s\n", out);
	return (rtrn);
}

// care of segfaults such as ps_print_clear in ps_error or stuff with chunks
int	main(int ac, char *av[])
{
	t_stack	a;
	t_stack	b;

	if (!ps_initialise_stack(ac, av, &a, &b))
		return (ps_error(&a, &b));
	if (!a.size)
		return (ps_bonus_out(&a, &b, NULL, 0));
	if (!ps_parser(&a, &b))
		return (ps_error(&a, &b));
	if (ps_issorted(&a, 1, 0) && !b.size)
		return (ps_bonus_out(&a, &b, "OK", 1));
	return (ps_bonus_out(&a, &b, "KO", 0));
}
