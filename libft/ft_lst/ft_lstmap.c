/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:24:53 by youness           #+#    #+#             */
/*   Updated: 2021/05/04 23:24:53 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

static t_list	*ft_manage_error(t_list **tail, void (*del)(void *))
{
	ft_lstclear(tail, del);
	return (0);
}

t_list	*ft_lstmap(t_list *tail, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst;
	t_list	*head;
	t_list	*node;

	lst = 0;
	while (tail)
	{
		node = malloc(sizeof(t_list));
		if (!node)
			return (ft_manage_error(&lst, del));
		node->next = 0;
		head->next = node;
		node->content = f(tail->content);
		if (!node->content)
			return (ft_manage_error(&lst, del));
		head = node;
		if (!lst)
			lst = head;
		tail = tail->next;
	}
	return (lst);
}
