/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initialise_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:17:28 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/30 15:41:52 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 or -1 if that is represented by str, else 1.
static int	ps_iszerone(char *str)
{
	int	sign;
	int	nb;

	nb = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (1);
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

// always returns 0.
static int	ps_free_split(char **els)
{
	int	i;

	i = 0;
	while (els && els[i])
	{
		free(els[i]);
		i++;
	}
	if (els)
		free(els);
	return (0);
}

static int	ps_add_elements(char *els[], t_stack *a)
{
	int	temp;
	size_t	count;

	count = 0;
	while (els && els[count])
		count++;
	if (!els || !count)
		return (0);
	while (count-- > 0)
	{
		if (!ps_isvalid(els[count]))
			return (0);
		temp = ft_atoi(els[count]);
		if ((temp == 0 || temp == -1) && temp != ps_iszerone(els[count]))
			return (0);
		if (!ps_isunique(temp, a))
			return (0);
		if (!ps_add_front(a, ps_create_element(temp)))
			return (0);
	}
	return (1);
}

// returns 0 on error, else 1.
int	ps_initialise_stack(int ac, char *av[], t_stack *a, t_stack *b)
{
	char	**els;

	ps_set_null(a, b);
	if (!ps_initialise_print(a, b) || !ps_add_emptychunk(a))
		return (0);
	while (ac-- > 1)
	{
		els = ft_split(av[ac], ' ');
		if (!ps_add_elements(els, a))
			return (ps_free_split(els));
		ps_free_split(els);
	}
	if (!ps_set_indexes(a))
		return (0);
	return (1);
}
