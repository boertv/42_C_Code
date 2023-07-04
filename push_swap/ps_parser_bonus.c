/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:55:34 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/04 14:55:45 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ps_bonus_out(t_stack *a, t_stack *b, const char *out, int rtrn)
{
	while (ps_del_back(a, 1) || ps_del_back(b, 1))
		(void)a;
	while (ps_del_chunk(a) || ps_del_chunk(b))
		(void)a;
	ps_print_clear(a);
	if (out)
		ft_printf("%s\n", out);
	return (rtrn);
}

static int	ps_freeturn(char *s, int r)
{
	if (s)
		free(s);
	return (r);
}

// always frees stdout
int	ps_isvalidop(char *stdout)
{
	if (!ft_strncmp(stdout, "pa\n", 4))
		return (ps_freeturn(stdout, 1));
	if (!ft_strncmp(stdout, "pb\n", 4))
		return (ps_freeturn(stdout, 1));
	if (!ft_strncmp(stdout, "sa\n", 4))
		return (ps_freeturn(stdout, 1));
	if (!ft_strncmp(stdout, "sb\n", 4))
		return (ps_freeturn(stdout, 1));
	if (!ft_strncmp(stdout, "ss\n", 4))
		return (ps_freeturn(stdout, 1));
	if (!ft_strncmp(stdout, "ra\n", 4))
		return (ps_freeturn(stdout, 1));
	if (!ft_strncmp(stdout, "rb\n", 4))
		return (ps_freeturn(stdout, 1));
	if (!ft_strncmp(stdout, "rr\n", 4))
		return (ps_freeturn(stdout, 1));
	if (!ft_strncmp(stdout, "rra\n", 5))
		return (ps_freeturn(stdout, 1));
	if (!ft_strncmp(stdout, "rrb\n", 5))
		return (ps_freeturn(stdout, 1));
	if (!ft_strncmp(stdout, "rrr\n", 5))
		return (ps_freeturn(stdout, 1));
	return (ps_freeturn(stdout, 0));
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
		ps_ss(a, b, 0);
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

// always frees stdout
int	ps_parser(t_stack *a, t_stack *b, char *stdout)
{
	while (stdout)
	{
		if (!ps_cmp_hub(a, b, stdout))
			return (0);
		stdout = get_next_line(0);
	}
	return (1);
}
