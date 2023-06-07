/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initialise_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:17:28 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/07 18:14:37 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 on error, else 1.
static int	ps_isvalid(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			return (0);
		str++;
	}
	return (1);
}

// returns 0 or -1 if that is represented by str, else 1.
static int	ps_iszerone(char *str)
{
	int	sign;
	int	nb;

	nb = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (((*str >= '2' && '9' >= *str)) || nb)
			return (1);
		else if (*str == '1')
			nb = 1;
		str++;
	}
	return (nb * sign);
}

// returns 0 on duplicate, else 1.
static int	ps_isunique(int nb, t_stack *a)
{
	t_dlilist	*list;

	list = a->start;
	while (list)
	{
		if (list->nb == nb)
			return (0);
		list = list->next;
	}
	return (1);
}

// returns 0 on error, else 1.
int	ps_initialise_stack(int ac, char *av[], t_stack *a, t_stack *b)
{
	int	temp;

	a->size = 0;
	b->size = 0;
	a->start = NULL;
	a->end = NULL;
	b->start = NULL;
	b->end = NULL;
	while (ac-- > 1)
	{
		if (!ps_isvalid(av[ac]))
			return (0);
		temp = ft_atoi(av[ac]);
		if ((temp == 0 || temp == -1) && temp != ps_iszerone(av[ac]))
			return (0);
		if (!ps_isunique(temp, a))
			return (0);
		if (!ps_add_front(a, ps_create_element(temp)))
			return (0);
	}
	return (1);
}
