/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:06:23 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/04 18:02:56 by bvercaem         ###   ########.fr       */
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
// 		ft_printf("}  s(%i, %i)c(%i, %i)\n"
// 		, a->min, a->max, a->chunks->min, a->chunks->max);
// 	else
// 		ft_printf("}  s(%i, %i)c(N/A, N/A)\n", a->min, a->max);
// 	if (a->size && (a->end->nb != list->nb))
// 	{
// 		ft_printf("!!!LIST END IS NOT CORRECT!!! end = %i\n", a->end->nb);
// 	}
// }

// GOOD IDEA:
// add an empty final chunck for rra all the ra without keeping count of 'r'.
// provides new difficulties tho,
// when grabbing the last chunck (ez fix in just one ft)
// and when checking if there is only one real chunck.

// rr values that i somehow already know are too big for the next push?
//	(might be easy enough with indexes)
//	(and ofc accordingly update the variable 'r',,, that doesn't exist yet)
int	main(int ac, char *av[])
{
	t_stack	a;
	t_stack	b;

	if (!ps_initialise_stack(ac, av, &a, &b))
		return (ps_error(&a, &b));
	if (a.size <= 5)
	{
		if (!ps_small_sorts(&a, &b))
			return (ps_error(&a, &b));
	}
	else
		if (!ps_big_sort(&a, &b))
			return (ps_error(&a, &b));
	ps_print_compression(&a);
	ps_print_ops(&a);
	ps_print_clear(&a);
	while (ps_del_back(&a, 1) || ps_del_back(&b, 1))
		(void)a;
	while (ps_del_chunk(&a) || ps_del_chunk(&b))
		(void)a;
}
