/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:42:41 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/17 11:07:04 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Doesn't protect against a NULL return from (*f). Should it?
// What if that is the wanted result? it'd be silly but i don't know.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*copy;

	if (!lst || !f || !del)
		return (NULL);
	copy = malloc(sizeof(t_list));
	if (!copy)
		return (NULL);
	start = copy;
	copy->content = (*f)(lst->content);
	lst = lst->next;
	while (lst)
	{
		copy->next = malloc(sizeof(t_list));
		if (!copy->next)
		{
			ft_lstclear(&start, (*del));
			return (NULL);
		}
		copy = copy->next;
		copy->content = (*f)(lst->content);
		lst = lst->next;
	}
	copy->next = NULL;
	return (start);
}
