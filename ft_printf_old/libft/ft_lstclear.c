/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:24:37 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/14 11:26:32 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// should we check the input of the 'del' ft before running it?
// i say the ft should check itself but i don't know if it always will.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;
	t_list	*temp;

	if (!lst || !del)
		return ;
	t = *lst;
	while (t)
	{
		temp = t;
		(*del)(t->content);
		t = t->next;
		free(temp);
	}
	*lst = NULL;
}
