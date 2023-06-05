/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:06:23 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/05 18:10:09 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* THIS IS A TEST FUNCTION TO PRINT MY ARRAY */
void	test_print(t_stack a, char c, char	*str)
{
	size_t	i;

	i = 0;
	if (str)
		ft_printf("Action performed = %s\n", str);
	ft_printf("%c: %i\n{", c, a->size);
	while (i + 1 < a->size)
	{
		ft_printf("%i, ", a->array[i]);
		i++;
	}
	if (a->size)
		ft_printf("%i", a->array[i]);
	ft_printf("}\n");
}

int	main(int ac, char *av[])
{
	struct s_stack	a;
	struct s_stack	b;

	if (ps_initialise_stack(--ac, av, &a, &b))
		return (ps_error());

/* THIS IS THE START OF MY LITTLE TEST AREA */
test_print(&a, 'a', NULL);
test_print(&b, 'b', NULL);
ps_swap(&a);
test_print(&a, 'a', "sa");
// ps_push(&a, &b);
// test_print(&a, 'a', "pb");
// test_print(&b, 'b', NULL);
// ps_rotate(&a);
// test_print(&a, 'a', "rotate");
// ps_rrotate(&a);
// test_print(&a, 'a', "reverse rotate");
/* THIS IS THE END OF MY LITTLE TEST AREA */
}
