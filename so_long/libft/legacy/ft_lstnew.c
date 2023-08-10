/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:25:59 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/13 10:38:20 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t;

	t = (t_list *) malloc(sizeof(t_list));
	if (!t)
		return (NULL);
	t->content = content;
	t->next = NULL;
	return (t);
}
