/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initialise_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:51:44 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/30 14:53:45 by bvercaem         ###   ########.fr       */
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

// returns 0 on error, else 1.
int	ps_isvalid(char *str)
{
	int		len;
	char	*max;

	if (*str == '-')
		max = "2147483648";
	else
		max = "2147483647";
	if (*str == '-' || *str == '+')
		str++;
	len = 0;
	while (str[len] && len < 11)
	{
		if (str[len] < '0' || '9' < str[len])
			return (0);
		len++;
	}
	if (len > 10)
		return (0);
	if (len == 10)
		while (len--)
			if (str[len] > max[len])
				return (0);
	return (1);
}
