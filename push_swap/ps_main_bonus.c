/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:47:57 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/30 15:17:04 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// care of segfaults such as ps_print_clear in ps_error or stuff with chunks
int	main(int ac, char *av[])
{
	t_stack	a;
	t_stack	b;
	char	*stdout;

	if (!ps_initialise_stack(ac, av, &a, &b))
		return (ps_error(&a, &b));
	if (!a.size)
		return (ps_bonus_out(&a, &b, NULL, 0));
	stdout = get_next_line(0);
	if (!stdout && ps_issorted(&a, 1, 0))
		return (ps_bonus_out(&a, &b, "OK", 1));
	if (stdout && ps_issorted(&a, 1, 0))
	{
		free (stdout);
		return (ps_bonus_out(&a, &b, "KO", 0));
	}
	if (!ps_parser(&a, &b, stdout))
		return (ps_error(&a, &b));
	if (ps_issorted(&a, 1, 0) && !b.size)
		return (ps_bonus_out(&a, &b, "OK", 1));
	return (ps_bonus_out(&a, &b, "KO", 0));
}
