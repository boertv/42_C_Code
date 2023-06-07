/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:06:23 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/07 18:03:08 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	test_print(t_stack *a, char c)
{
/* THIS IS A TEST FUNCTION TO PRINT MY CONTAINERS */
	t_dlilist	*list;

	list = a->start;
	ft_printf("%c[%i] {", c, a->size);
	while (list && list->next)
	{
		ft_printf("%i, ", list->nb);
		list = list->next;
	}
	if (list)
		ft_printf("%i", list->nb);
	ft_printf("}\n");
	if (a->end->nb != list->nb)
	{
		ft_printf("LIST END IS NOT CORRECT!!! end = %i\n\n", a->end->nb);
	}
}

int	main(int ac, char *av[])
{
	t_stack	a;
	t_stack	b;

	if (!ps_initialise_stack(ac, av, &a, &b))
		return (ps_error());

/* THIS IS THE START OF MY LITTLE TEST AREA */

test_print(&a, 'a');
ps_push(&a, &b, 'b');
ps_push(&a, &b, 'b');
test_print(&a, 'a');
test_print(&b, 'b');
ps_ss(&a, &b);
test_print(&a, 'a');
test_print(&b, 'b');

/* THIS IS THE END OF MY LITTLE TEST AREA */

	while (ps_del_back(&a, 1) || ps_del_back(&b, 1))
		(void)a;

	// ft_printf("\n\n");
	// system("LEAKS push_swap");
}
