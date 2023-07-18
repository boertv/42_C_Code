/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:15:35 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/18 17:17:43 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// shifts everything down and sets 0
void	ft_strshift(char *s)
{
	if (!s || !s[0])
		return ;
	while (s[1])
	{
		s[0] = s[1];
		s++;
	}
	s[0] = 0;
}