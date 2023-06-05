/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initialise_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:17:28 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/05 18:06:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns -1 on error, else 0.
static int	ps_isvalid(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			return (-1);
		str++;
	}
	return (0);
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

// returns -1 on duplicate, else 0.
static int	ps_check_dup(int nb, t_stack a, size_t start)
{
	while (start < a->size)
	{
		if (nb == a->array[start])
			return (-1);
		start++;
	}
	return (0);
}

// returns -1 on error, else 0.
int	ps_initialise_stack(int ac, char *av[], t_stack a, t_stack b)
{
	int	tempa[ac];
	int	tempb[ac];
	int	bin;

	a->size = ac;
	b->size = 0;
	a->array = tempa;
	b->array = tempb;
	while (ac > 0)
	{
		if (ps_isvalid(av[ac]))
			return (-1);
		bin = ft_atoi(av[ac]);
		if ((bin == 0 || bin == -1) && bin != ps_iszerone(av[ac]))
			return (-1);
		if (ps_check_dup(bin, a, ac))
			return (-1);
		a->array[ac - 1] = bin;
		ac--;
	}
	return (0);
}
