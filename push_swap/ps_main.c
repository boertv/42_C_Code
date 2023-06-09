/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:06:23 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/09 13:37:47 by bvercaem         ###   ########.fr       */
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
	ft_printf("}  (%i, %i)\n", a->min, a->max);
	if (a->size && (a->end->nb != list->nb))
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
	if (ac <= 6)
		ps_small_sorts(&a, &b, ac - 1);

/* THIS IS THE START OF MY LITTLE TEST AREA */

ft_printf("-----------\n");
if (b.size)
{
	ft_printf("!!STACK 'b' ISN'T EMPTY!!\n");
	test_print(&b, 'b');
}
if (!ps_issorted(&a, 1))
{
	ft_printf("!!STACK 'a' ISN'T SORTED!!\n");
	test_print(&a, 'a');
}
else if (!b.size)
	ft_printf("all looks good!\n");

// ps_push(&a, &b, 'b');
// test_print(&a, 'a');
// test_print(&b, 'b');
// ps_push(&b, &a, 'a');
// test_print(&a, 'a');
// test_print(&b, 'b');
// ps_push(&b, &a, 'a');
// test_print(&a, 'a');
// test_print(&b, 'b');

/* THIS IS THE END OF MY LITTLE TEST AREA */

	while (ps_del_back(&a, 1) || ps_del_back(&b, 1))
		(void)a;

	// ft_printf("\n\n");
	// system("LEAKS push_swap");
}
