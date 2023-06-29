/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:55:34 by bvercaem          #+#    #+#             */
/*   Updated: 2023/06/29 18:32:25 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ps_freeturn(char *s, int r)
{
	if (s)
		free(s);
	return (r);
}

static int	ps_cmp_hub(t_stack *a, t_stack *b, char *stdout)
{
	if (!ft_strncmp(stdout, "pa\n", 4))
		ps_push(b, a, 0);
	else if (!ft_strncmp(stdout, "pb\n", 4))
		ps_push(a, b, 0);
	else if (!ft_strncmp(stdout, "sa\n", 4))
		ps_swap(a, NULL, 0);
	else if (!ft_strncmp(stdout, "sb\n", 4))
		ps_swap(b, NULL, 0);
	else if (!ft_strncmp(stdout, "ss\n", 4))
		ps_swap(a, b, 0);
	else if (!ft_strncmp(stdout, "ra\n", 4))
		ps_rotate(a, 0);
	else if (!ft_strncmp(stdout, "rb\n", 4))
		ps_rotate(b, 0);
	else if (!ft_strncmp(stdout, "rr\n", 4))
		ps_rr(a, b, 0);
	else if (!ft_strncmp(stdout, "rra\n", 5))
		ps_rrotate(a, 0);
	else if (!ft_strncmp(stdout, "rrb\n", 5))
		ps_rrotate(b, 0);
	else if (!ft_strncmp(stdout, "rrr\n", 5))
		ps_rrr(a, b, 0);
	else
		return (ps_freeturn(stdout, 0));
	return (ps_freeturn(stdout, 1));
}

int	ps_parser(t_stack *a, t_stack *b)
{
	char	*stdout;

	stdout = get_next_line(1);
	while (stdout)
	{
		if (!ps_cmp_hub(a, b, stdout))
			return (0);
		stdout = get_next_line(1);
	}
	return (1);
}
