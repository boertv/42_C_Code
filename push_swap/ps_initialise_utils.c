/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initialise_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:51:44 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/30 16:20:16 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_set_null(t_stack *a, t_stack *b)
{
	a->a = 1;
	b->a = 0;
	a->size = 0;
	b->size = 0;
	a->start = NULL;
	a->end = NULL;
	a->chunks = NULL;
	b->start = NULL;
	b->end = NULL;
	b->chunks = NULL;
}

static int	ps_overflow_check(char *str)
{
	char	*max;
	int		len;

	if (str[0] == '-')
		max = "2147483648";
	else
		max = "2147483647";
	if (str[0] == '-' || str[0] == '+')
		str++;
	len = 0;
	while (len < 10)
	{
		if (str[len] > max[len])
			return (0);
		if (str[len] < max[len])
			break ;
		len++;
	}
	return (1);
}

// returns 0 on error, else 1.
int	ps_isvalid(char *str)
{
	int	len;
	int	s;

	s = 0;
	if (str[0] == '-' || str[0] == '+')
		s = 1;
	len = 0;
	while (str[s + len] && len < 11)
	{
		if (str[s + len] < '0' || '9' < str[s + len])
			return (0);
		len++;
	}
	if (len > 10)
		return (0);
	if (len == 10)
		return (ps_overflow_check(str));
	return (1);
}
