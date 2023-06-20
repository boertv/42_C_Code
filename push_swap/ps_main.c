/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:06:23 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/20 18:16:08 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	test_print(t_stack *a, char c)
// {
// /* THIS IS A TEST FUNCTION TO PRINT MY CONTAINERS */
// 	t_dlilist	*list;

// 	list = a->start;
// 	if (a->chunks)
// 		ft_printf("%c: s[%i]c[%i] {", c, a->size, a->chunks->size);
// 	else
// 		ft_printf("%c: s[%i]c[N/A] {", c, a->size);
// 	while (list && list->next)
// 	{
// 		ft_printf("%i, ", list->nb);
// 		list = list->next;
// 	}
// 	if (list)
// 		ft_printf("%i", list->nb);
// 	if (a->chunks)
// 		ft_printf("}  s(%i, %i)c(%i, %i)\n", a->min, a->max, a->chunks->min, a->chunks->max);
// 	else
// 		ft_printf("}  s(%i, %i)c(N/A, N/A)\n", a->min, a->max);
// 	if (a->size && (a->end->nb != list->nb))
// 	{
// 		ft_printf("!!!LIST END IS NOT CORRECT!!! end = %i\n", a->end->nb);
// 	}
// }

int	main(int ac, char *av[])
{
// return "Error\n" on std_error after malloc fail?
// outliers fuck my avg up real good but what can you do? (short of sorting it before sorting it)
	t_stack	a;
	t_stack	b;

	if (!ps_initialise_stack(ac, av, &a, &b))
		return (ps_error(&a, &b));

// test_print(&a, 'a');

// SMALL SORTS SEGFAULTS
	if (ac <= 6)
	{
		if (!ps_small_sorts(&a, &b))
			return (ps_error(&a, &b));
	}
	else
		if (!ps_big_sort(&a, &b))
			return (ps_error(&a, &b));
	ps_print_trim(&a);
	ps_print_ops(&a);
	ps_print_clear(&a);

/* THIS IS THE START OF MY LITTLE TEST AREA */

// if (b.size || b.start || b.end)
// {
// 	ft_printf("\n[!!!] [STACK 'b' ISN'T EMPTY] [!!!]\n");
// 	test_print(&b, 'b');
// }
// if (!ps_issorted(&a, 1, 0))
// {
// 	ft_printf("\n[!!!] [STACK 'a' ISN'T SORTED] [!!!]\n");
// 	test_print(&a, 'a');
// }

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
	while (ps_del_chunk(&a) || ps_del_chunk(&b))
		(void)a;

// ft_printf("\n\t--------------------------------\n\n");
// system("leaks push_swap");
}
