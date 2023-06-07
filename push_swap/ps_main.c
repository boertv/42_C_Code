/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:06:23 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/07 15:26:03 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	test_print(t_stack *a, char c, char	*str)
{
/* THIS IS A TEST FUNCTION TO PRINT MY ARRAY */
	t_dlilist	*list;

	list = a->start;
	if (str)
		ft_printf("Action performed = %s\n", str);
	ft_printf("%c[%i] {", c, a->size);
	while (list && list->next)
	{
		ft_printf("%i, ", list->nb);
		list = list->next;
	}
	if (list)
		ft_printf("%i", list->nb);
	ft_printf("}\n");
}

int	main(int ac, char *av[])
{
	t_stack	a;
	t_stack	b;

	if (!ps_initialise_stack(ac, av, &a, &b))
		return (ps_error());

/* THIS IS THE START OF MY LITTLE TEST AREA */

	test_print(&a, 'a', NULL);
	test_print(&b, 'b', NULL);
	ps_swap(&a);
	test_print(&a, 'a', "sa");
	ps_push(&a, &b);
	test_print(&a, 'a', "pb");
	test_print(&b, 'b', NULL);
	ps_rotate(&a);
	test_print(&a, 'a', "rotate");
	ps_rrotate(&a);
	test_print(&a, 'a', "reverse rotate");

/* THIS IS THE END OF MY LITTLE TEST AREA */

	while (ps_del_back(&a, 1) || ps_del_back(&b, 1))
		(void)a;

	// ft_printf("\n\n");
	// system("LEAKS push_swap");
}
